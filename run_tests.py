#!/usr/bin/env python3
"""Runner for the circom_tests suite.

A test case is any directory D that contains D/<basename(D)>.circom plus at
least one expectation file (see README.md). For every case and every requested
simplification level (--O0/--O1/--O2) the runner compiles the circuit with the
given circom binary and checks the expectations:

  witness/input.json            -> correct case: compile, compute the witness
                                   with wasm (node) and C++ (make), check that
                                   both witnesses are equal and satisfy the R1CS
  witness/expected_outputs.json -> values of the main outputs (checked via .sym)
  witness/result_O<n>.wtns      -> golden witness (snapshot, reported as DIFF)
  r1cs/<case>_O<n>.r1cs         -> golden r1cs (snapshot, reported as DIFF)
  expected_log.txt              -> exact lines printed by log() during witness gen.
  error.txt                     -> golden stderr of a failing compilation
  expected_error.txt            -> substrings the compilation stderr must contain
  expected_runtime_error.txt    -> compiles, witness generation must fail and
                                   print these substrings ("wasm:"/"cpp:" prefix
                                   restricts a line to one backend)
  flags.txt                     -> extra circom flags (e.g. --sanity_check 3)
  levels.txt                    -> simplification levels for this case (e.g. 0 2)
  known_bug.txt                 -> the case is expected to fail (XFAIL/XPASS)

Statuses: PASS, FAIL (semantic failure), DIFF (only a golden snapshot differs),
XFAIL, XPASS, SKIP. The exit code is 1 iff some case is FAIL.
"""

import argparse
import concurrent.futures
import difflib
import hashlib
import json
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile
import time

ANSI_RE = re.compile(r"\x1B\[[0-9;]*[A-Za-z]")
PANIC_MARKERS = ["panicked at", "has overflowed its stack", "fatal runtime error", "internal error"]
SPEC_FILES = ["error.txt", "expected_error.txt", "expected_runtime_error.txt"]


# ---------------------------------------------------------------- binary files

def read_sections(path, magic):
    with open(path, "rb") as f:
        data = f.read()
    if data[:4] != magic:
        raise ValueError(f"{path}: bad magic {data[:4]!r}")
    _version, nsections = struct.unpack_from("<II", data, 4)
    pos = 12
    sections = {}
    for _ in range(nsections):
        stype, ssize = struct.unpack_from("<IQ", data, pos)
        pos += 12
        sections.setdefault(stype, data[pos:pos + ssize])
        pos += ssize
    return sections


def read_wtns(path):
    sections = read_sections(path, b"wtns")
    header = sections[1]
    n8 = struct.unpack_from("<I", header, 0)[0]
    prime = int.from_bytes(header[4:4 + n8], "little")
    nwit = struct.unpack_from("<I", header, 4 + n8)[0]
    body = sections[2]
    values = [int.from_bytes(body[i * n8:(i + 1) * n8], "little") for i in range(nwit)]
    return prime, values


def read_r1cs(path):
    sections = read_sections(path, b"r1cs")
    header = sections[1]
    n8 = struct.unpack_from("<I", header, 0)[0]
    prime = int.from_bytes(header[4:4 + n8], "little")
    nwires, _nout, _npubin, _nprvin = struct.unpack_from("<IIII", header, 4 + n8)
    _nlabels = struct.unpack_from("<Q", header, 4 + n8 + 16)[0]
    ncons = struct.unpack_from("<I", header, 4 + n8 + 24)[0]
    body = sections[2]
    pos = 0
    constraints = []
    for _ in range(ncons):
        lcs = []
        for _ in range(3):
            nterms = struct.unpack_from("<I", body, pos)[0]
            pos += 4
            lc = []
            for _ in range(nterms):
                wire = struct.unpack_from("<I", body, pos)[0]
                coef = int.from_bytes(body[pos + 4:pos + 4 + n8], "little")
                pos += 4 + n8
                lc.append((wire, coef))
            lcs.append(lc)
        constraints.append(lcs)
    return prime, nwires, constraints


def check_r1cs(r1cs_path, witness):
    """Returns None if the witness satisfies every constraint, else a message."""
    prime, nwires, constraints = read_r1cs(r1cs_path)
    if len(witness) != nwires:
        return f"witness has {len(witness)} values but the r1cs has {nwires} wires"
    for idx, (a, b, c) in enumerate(constraints):
        va = sum(coef * witness[w] for w, coef in a) % prime
        vb = sum(coef * witness[w] for w, coef in b) % prime
        vc = sum(coef * witness[w] for w, coef in c) % prime
        if (va * vb - vc) % prime != 0:
            return f"constraint {idx} is not satisfied"
    return None


def read_sym(path):
    signals = {}
    with open(path) as f:
        for line in f:
            parts = line.strip().split(",", 3)
            if len(parts) == 4:
                signals[parts[3]] = int(parts[1])
    return signals


def flatten_expected(prefix, value, out):
    if isinstance(value, list):
        for i, v in enumerate(value):
            flatten_expected(f"{prefix}[{i}]", v, out)
    elif isinstance(value, dict):
        for k, v in value.items():
            flatten_expected(f"{prefix}.{k}", v, out)
    else:
        out[prefix] = int(value)


# ------------------------------------------------------------------- helpers

def run(cmd, cwd=None, timeout=None):
    """Runs cmd and returns (returncode, combined output). Timeouts give rc=None."""
    try:
        p = subprocess.run(cmd, cwd=cwd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                           timeout=timeout)
        return p.returncode, p.stdout.decode("utf-8", errors="replace")
    except subprocess.TimeoutExpired as e:
        out = (e.stdout or b"").decode("utf-8", errors="replace")
        return None, out + f"\n<timeout after {timeout}s>"


def has_panic(text):
    return any(m in text for m in PANIC_MARKERS)


def read_text(path):
    with open(path) as f:
        return f.read()


def read_lines(path):
    return [l.rstrip("\n") for l in read_text(path).splitlines() if l.strip()]


def normalize_errors(text):
    text = ANSI_RE.sub("", text)
    text = re.sub(r'"(?:[^"\n]*/)?([^"/\n]+\.circom)"', r'"\1"', text)
    text = re.sub(r"Assuming pragma version (\([^)]*\)|\d+\.\d+\.\d+)", "Assuming pragma version (VERSION)", text)
    text = re.sub(r"pragma circom \d+\.\d+\.\d+", "pragma circom VERSION", text)
    return "\n".join(l.rstrip() for l in text.strip().splitlines())


def error_codes(text):
    return sorted(re.findall(r"error\[(\w+)\]", ANSI_RE.sub("", text)))


def outputs_log(text):
    return [l for l in text.splitlines() if l.strip()]


class CppCache:
    """Caches the object files shared by every generated C++ project (fr, calcwit, main),
    so that only <circuit>.cpp is compiled for each case."""

    def __init__(self, root):
        self.root = root
        os.makedirs(root, exist_ok=True)

    def key(self, cpp_dir, run_name):
        h = hashlib.sha256()
        for name in sorted(os.listdir(cpp_dir)):
            path = os.path.join(cpp_dir, name)
            if name.startswith(run_name + ".") or not os.path.isfile(path):
                continue
            if name.endswith((".cpp", ".hpp", ".asm", ".h")) or name.lower() == "makefile":
                h.update(name.encode())
                with open(path, "rb") as f:
                    h.update(f.read())
        return h.hexdigest()[:24]

    def restore(self, cpp_dir, run_name):
        src = os.path.join(self.root, self.key(cpp_dir, run_name))
        if not os.path.isdir(src):
            return
        now = time.time() + 1
        for name in os.listdir(src):
            dst = os.path.join(cpp_dir, name)
            shutil.copyfile(os.path.join(src, name), dst)
            os.utime(dst, (now, now))

    def store(self, cpp_dir, run_name):
        dst = os.path.join(self.root, self.key(cpp_dir, run_name))
        if os.path.isdir(dst):
            return
        tmp = tempfile.mkdtemp(dir=self.root)
        for name in os.listdir(cpp_dir):
            if name.endswith(".o") and name != run_name + ".o":
                shutil.copyfile(os.path.join(cpp_dir, name), os.path.join(tmp, name))
        try:
            os.rename(tmp, dst)
        except OSError:
            shutil.rmtree(tmp, ignore_errors=True)


# ---------------------------------------------------------------- test cases

class Case:
    def __init__(self, path, root):
        self.path = path
        self.name = os.path.basename(path)
        self.rel = os.path.relpath(path, root)
        self.circom = os.path.join(path, self.name + ".circom")

    def file(self, *parts):
        return os.path.join(self.path, *parts)

    def exists(self, *parts):
        return os.path.exists(self.file(*parts))

    @property
    def kind(self):
        if self.exists("error.txt") and "error[" not in read_text(self.file("error.txt")) \
                and "Everything went okay" in read_text(self.file("error.txt")):
            return "compile_ok"  # some error.txt files record a successful compilation
        if self.exists("error.txt") or self.exists("expected_error.txt"):
            return "compile_error"
        if self.exists("expected_runtime_error.txt"):
            return "runtime_error"
        if self.exists("witness", "input.json"):
            return "correct"
        return None

    def flags(self):
        return read_text(self.file("flags.txt")).split() if self.exists("flags.txt") else []

    def levels(self, default):
        if self.exists("levels.txt"):
            return [int(x) for x in read_text(self.file("levels.txt")).split()]
        return default


def discover(roots, base):
    cases = []
    for root in roots:
        for dirpath, dirnames, filenames in os.walk(root):
            dirnames[:] = sorted(d for d in dirnames
                                 if not d.startswith(".") and not d.endswith(("_js", "_cpp")))
            name = os.path.basename(dirpath)
            if name + ".circom" in filenames:
                case = Case(dirpath, base)
                if case.kind is not None:
                    cases.append(case)
    return cases


class Runner:
    def __init__(self, args):
        self.args = args
        self.cpp_cache = CppCache(os.path.join(args.workdir, "cpp_cache"))

    def compile(self, case, level, out_dir, outputs):
        cmd = [self.args.circom, case.circom, "-o", out_dir, f"--O{level}"] + outputs + case.flags()
        for lib in self.args.lib:
            cmd += ["-l", lib]
        return run(cmd, cwd=case.path, timeout=self.args.compile_timeout)

    def wasm_witness(self, case, out_dir, input_json, wtns):
        js = os.path.join(out_dir, case.name + "_js")
        return run(["node", os.path.join(js, "generate_witness.js"), os.path.join(js, case.name + ".wasm"),
                    input_json, wtns], timeout=self.args.witness_timeout)

    def cpp_witness(self, case, out_dir, input_json, wtns):
        cpp = os.path.join(out_dir, case.name + "_cpp")
        self.cpp_cache.restore(cpp, case.name)
        rc, out = run(["make", "-s"], cwd=cpp, timeout=self.args.make_timeout)
        if rc != 0:
            return "make", rc, out
        self.cpp_cache.store(cpp, case.name)
        rc, out = run([os.path.join(cpp, case.name), input_json, wtns], cwd=cpp,
                      timeout=self.args.witness_timeout)
        return "run", rc, out

    def backends(self):
        return ["wasm"] + ([] if self.args.no_cpp else ["cpp"])

    # Each check_* returns a list of (severity, message), severity in {"FAIL", "DIFF"}.

    def check_compile_error(self, case, level, out_dir):
        rc, out = self.compile(case, level, out_dir, ["--r1cs", "--sym", "--wasm", "--c"])
        problems = []
        if has_panic(out):
            problems.append(("FAIL", "compiler panicked:\n" + tail(out)))
        if rc == 0:
            problems.append(("FAIL", "compilation succeeded but an error was expected"))
            return problems, out
        if rc is None:
            problems.append(("FAIL", "compilation timed out"))
            return problems, out
        if case.exists("expected_error.txt"):
            clean = ANSI_RE.sub("", out)
            for needle in read_lines(case.file("expected_error.txt")):
                if needle not in clean:
                    problems.append(("FAIL", f"missing expected error text: {needle!r}\n" + tail(out)))
        if case.exists("error.txt"):
            golden = read_text(case.file("error.txt"))
            if normalize_errors(golden) != normalize_errors(out):
                severity = "DIFF" if error_codes(golden) == error_codes(out) else "FAIL"
                diff = difflib.unified_diff(normalize_errors(golden).splitlines(),
                                            normalize_errors(out).splitlines(), lineterm="", n=1)
                problems.append((severity, "stderr differs from error.txt (codes "
                                 f"{error_codes(golden)} vs {error_codes(out)}):\n" +
                                 "\n".join(list(diff)[2:30])))
        return problems, out

    def check_compile_ok(self, case, level, out_dir):
        rc, out = self.compile(case, level, out_dir, ["--r1cs", "--sym", "--wasm", "--c"])
        if rc != 0:
            return [("FAIL", "compilation failed but error.txt records a successful one:\n" + tail(out))], out
        return [], out

    def check_runtime_error(self, case, level, out_dir):
        rc, out = self.compile(case, level, out_dir, ["--wasm", "--c"])
        if rc != 0:
            return [("FAIL", "compilation failed:\n" + tail(out))], out
        expected = read_lines(case.file("expected_runtime_error.txt"))
        input_json = case.file("witness", "input.json")
        problems = []
        log = out
        for backend in self.backends():
            wtns = os.path.join(out_dir, f"{backend}.wtns")
            if backend == "wasm":
                rc, wout = self.wasm_witness(case, out_dir, input_json, wtns)
            else:
                step, rc, wout = self.cpp_witness(case, out_dir, input_json, wtns)
                if step == "make":
                    problems.append(("FAIL", "C++ build failed:\n" + tail(wout)))
                    continue
            log += f"\n--- {backend} ---\n" + wout
            if rc == 0:
                problems.append(("FAIL", f"{backend}: witness generation succeeded but an error was expected"))
                continue
            if rc is None:
                problems.append(("FAIL", f"{backend}: witness generation timed out"))
                continue
            for line in expected:
                m = re.match(r"^(wasm|cpp):\s*(.*)$", line)
                if m and m.group(1) != backend:
                    continue
                needle = m.group(2) if m else line
                if needle not in wout:
                    problems.append(("FAIL", f"{backend}: missing runtime error text {needle!r}\n" + tail(wout)))
        return problems, log

    def check_correct(self, case, level, out_dir):
        rc, out = self.compile(case, level, out_dir, ["--r1cs", "--sym", "--wasm"] +
                               ([] if self.args.no_cpp else ["--c"]))
        if rc != 0:
            return [("FAIL", "compilation failed:\n" + tail(out))], out
        problems = []
        log = out
        r1cs = os.path.join(out_dir, case.name + ".r1cs")
        sym = os.path.join(out_dir, case.name + ".sym")
        input_json = case.file("witness", "input.json")
        witnesses = {}
        logs = {}
        for backend in self.backends():
            wtns = os.path.join(out_dir, f"{backend}.wtns")
            if backend == "wasm":
                rc, wout = self.wasm_witness(case, out_dir, input_json, wtns)
            else:
                step, rc, wout = self.cpp_witness(case, out_dir, input_json, wtns)
                if step == "make":
                    problems.append(("FAIL", "C++ build failed:\n" + tail(wout)))
                    continue
            log += f"\n--- {backend} ---\n" + wout
            if rc != 0 or not os.path.exists(wtns):
                why = "timed out" if rc is None else f"exit code {rc}"
                problems.append(("FAIL", f"{backend}: witness generation failed ({why}):\n" + tail(wout)))
                continue
            witnesses[backend] = read_wtns(wtns)[1]
            logs[backend] = outputs_log(wout)
        if not witnesses:
            return problems, log

        if len(witnesses) == 2 and witnesses["wasm"] != witnesses["cpp"]:
            problems.append(("FAIL", "wasm and C++ witnesses differ"))
        if len(logs) == 2 and logs["wasm"] != logs["cpp"]:
            problems.append(("FAIL", "wasm and C++ logs differ:\n" + "\n".join(logs["wasm"]) +
                             "\n  vs\n" + "\n".join(logs["cpp"])))
        backend, witness = next(iter(witnesses.items()))
        if not self.args.no_r1cs_check:
            msg = check_r1cs(r1cs, witness)
            if msg:
                problems.append(("FAIL", f"{backend} witness does not satisfy the R1CS: {msg}"))
        if case.exists("witness", "expected_outputs.json"):
            expected = {}
            for k, v in json.loads(read_text(case.file("witness", "expected_outputs.json"))).items():
                flatten_expected("main." + k, v, expected)
            prime = read_r1cs(r1cs)[0]
            signals = read_sym(sym)
            for name, value in expected.items():
                idx = signals.get(name)
                if idx is None or idx < 0:
                    problems.append(("FAIL", f"output {name} not found in the witness"))
                elif witness[idx] != value % prime:
                    got = witness[idx]
                    if got > prime // 2:
                        got -= prime
                    problems.append(("FAIL", f"output {name} = {got}, expected {value}"))
        if case.exists("expected_log.txt"):
            expected_log = read_lines(case.file("expected_log.txt"))
            for b, lines in logs.items():
                if lines != expected_log:
                    problems.append(("FAIL", f"{b}: log differs from expected_log.txt:\n" + "\n".join(lines)))
        golden_wtns = case.file("witness", f"result_O{level}.wtns")
        if os.path.exists(golden_wtns) and read_wtns(golden_wtns)[1] != witness:
            problems.append(("DIFF", f"witness differs from witness/result_O{level}.wtns"))
        golden_r1cs = case.file("r1cs", f"{case.name}_O{level}.r1cs")
        if os.path.exists(golden_r1cs):
            with open(golden_r1cs, "rb") as f1, open(r1cs, "rb") as f2:
                if f1.read() != f2.read():
                    problems.append(("DIFF", f"r1cs differs from r1cs/{case.name}_O{level}.r1cs"))
        if self.args.generate:
            self.generate(case, level, out_dir, witness_path=os.path.join(out_dir, f"{backend}.wtns"))
        return problems, log

    def generate(self, case, level, out_dir, witness_path):
        os.makedirs(case.file("r1cs"), exist_ok=True)
        for ext in ("r1cs", "sym"):
            dst = case.file("r1cs", f"{case.name}_O{level}.{ext}")
            if self.args.force or not os.path.exists(dst):
                shutil.copyfile(os.path.join(out_dir, f"{case.name}.{ext}"), dst)
        dst = case.file("witness", f"result_O{level}.wtns")
        if self.args.force or not os.path.exists(dst):
            shutil.copyfile(witness_path, dst)

    def run_case(self, case):
        start = time.time()
        known_bug = read_text(case.file("known_bug.txt")).strip() if case.exists("known_bug.txt") else None
        details = []
        severity = "PASS"
        out_root = tempfile.mkdtemp(prefix=case.name + "_", dir=self.args.workdir)
        for level in case.levels(self.args.levels):
            out_dir = os.path.join(out_root, f"O{level}")
            os.makedirs(out_dir)
            try:
                if case.kind == "compile_error":
                    problems, log = self.check_compile_error(case, level, out_dir)
                elif case.kind == "compile_ok":
                    problems, log = self.check_compile_ok(case, level, out_dir)
                elif case.kind == "runtime_error":
                    problems, log = self.check_runtime_error(case, level, out_dir)
                else:
                    problems, log = self.check_correct(case, level, out_dir)
            except Exception as e:  # malformed outputs, missing files...
                problems, log = [("FAIL", f"runner exception: {e!r}")], ""
            for sev, msg in problems:
                details.append(f"[O{level}] {sev}: {msg}")
                if sev == "FAIL" or severity == "PASS":
                    severity = sev
            if problems and self.args.verbose:
                details.append(f"[O{level}] log:\n{log}")
        if known_bug is not None:
            severity = "XFAIL" if severity == "FAIL" else "XPASS"
        if not self.args.keep:
            shutil.rmtree(out_root, ignore_errors=True)
        return case, severity, details, known_bug, time.time() - start


def tail(text, n=25):
    lines = ANSI_RE.sub("", text).strip().splitlines()
    return "\n".join("    " + l for l in lines[-n:])


def main():
    here = os.path.dirname(os.path.abspath(__file__))
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--circom", default=shutil.which("circom"), help="circom binary to test")
    ap.add_argument("--only", nargs="*", default=[], help="directories to run (default: whole suite)")
    ap.add_argument("--levels", default="0,1,2", help="simplification levels, e.g. 0,2")
    ap.add_argument("--no-cpp", action="store_true", help="skip C++ witness generation")
    ap.add_argument("--no-r1cs-check", action="store_true", help="skip checking the witness against the R1CS")
    ap.add_argument("--generate", action="store_true", help="write missing golden wtns/r1cs/sym files")
    ap.add_argument("--force", action="store_true", help="with --generate, overwrite existing golden files")
    ap.add_argument("-l", "--lib", action="append", default=[], help="extra -l library path for circom")
    ap.add_argument("--jobs", type=int, default=max(1, (os.cpu_count() or 2) // 2))
    ap.add_argument("--workdir", default=None, help="where to put build outputs (default: a temp dir)")
    ap.add_argument("--keep", action="store_true", help="keep build outputs")
    ap.add_argument("--compile-timeout", type=int, default=300)
    ap.add_argument("--make-timeout", type=int, default=600)
    ap.add_argument("--witness-timeout", type=int, default=120)
    ap.add_argument("--report", help="write a markdown report to this file")
    ap.add_argument("-v", "--verbose", action="store_true", help="include full logs of failing cases")
    args = ap.parse_args()
    if not args.circom:
        ap.error("no circom binary found, use --circom")
    args.circom = os.path.abspath(args.circom)
    args.levels = [int(x) for x in args.levels.split(",")]
    args.workdir = os.path.abspath(args.workdir or tempfile.mkdtemp(prefix="circom_tests_"))
    os.makedirs(args.workdir, exist_ok=True)

    roots = [os.path.abspath(p) for p in args.only] or [here]
    cases = discover(roots, here)
    _, version = run([args.circom, "--version"])
    print(f"circom: {args.circom} ({version.strip()})\ncases: {len(cases)}  levels: {args.levels}  "
          f"backends: {'wasm' if args.no_cpp else 'wasm+cpp'}  workdir: {args.workdir}\n", flush=True)

    runner = Runner(args)
    results = []
    with concurrent.futures.ThreadPoolExecutor(max_workers=args.jobs) as pool:
        for case, status, details, known_bug, secs in pool.map(runner.run_case, cases):
            results.append((case, status, details, known_bug, secs))
            print(f"{status:6} {case.rel}  ({secs:.1f}s)", flush=True)
            if status in ("FAIL", "XPASS", "DIFF") or (args.verbose and details):
                for d in details:
                    print("       " + d.replace("\n", "\n       "))

    counts = {}
    for _, status, _, _, _ in results:
        counts[status] = counts.get(status, 0) + 1
    summary = "  ".join(f"{k}: {v}" for k, v in sorted(counts.items()))
    print("\n" + summary)
    if args.report:
        write_report(args, version, results, summary)
    sys.exit(1 if counts.get("FAIL") else 0)


def write_report(args, version, results, summary):
    with open(args.report, "w") as f:
        f.write(f"# circom_tests report\n\n- circom: `{args.circom}` ({version.strip()})\n"
                f"- levels: {args.levels}, backends: {'wasm' if args.no_cpp else 'wasm+cpp'}\n"
                f"- {summary}\n\n| status | case | known bug |\n|---|---|---|\n")
        for case, status, _, known_bug, _ in sorted(results, key=lambda r: r[0].rel):
            f.write(f"| {status} | `{case.rel}` | {(known_bug or '').splitlines()[0] if known_bug else ''} |\n")
        f.write("\n## Details\n")
        for case, status, details, _, _ in sorted(results, key=lambda r: r[0].rel):
            if details:
                f.write(f"\n### {status} `{case.rel}`\n\n```\n" + "\n".join(details) + "\n```\n")


if __name__ == "__main__":
    main()
