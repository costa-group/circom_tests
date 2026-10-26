#!/usr/bin/env python3
"""Generates the cases of release_2.2.4 (hand-written expectations).

Usage: python3 tools/gen_release_2.2.4.py release_2.2.4
Every case directory is regenerated; other files in the root (REPORT.md) are kept.
"""
import json, os, shutil, sys, textwrap

ROOT = sys.argv[1]
P = 21888242871839275222246405745257275088548364400416034343698204186575808495617
GOLDILOCKS = 2**64 - 2**32 + 1
OOB = ["wasm: Out of bounds array access", "cpp: Out of bounds exception"]
DIVZ = ["wasm: Division by zero", "cpp: Division by zero in template/function"]
S3 = "--sanity_check 3"


def case(path, src, inputs=None, outputs=None, flags=None, runtime_error=None, error=None,
         known_bug=None, levels=None, log=None, notes=None):
    d = os.path.join(ROOT, path)
    name = os.path.basename(d)
    os.makedirs(d, exist_ok=True)

    def w(fname, text):
        os.makedirs(os.path.dirname(os.path.join(d, fname)) or d, exist_ok=True)
        with open(os.path.join(d, fname), "w") as f:
            f.write(text)

    w(name + ".circom", textwrap.dedent(src).strip() + "\n")
    if inputs is not None:
        w("witness/input.json", json.dumps(inputs) + "\n")
    if outputs is not None:
        w("witness/expected_outputs.json", json.dumps(outputs, indent=1) + "\n")
    if flags:
        w("flags.txt", flags + "\n")
    if runtime_error:
        w("expected_runtime_error.txt", "\n".join(runtime_error) + "\n")
    if error:
        w("expected_error.txt", "\n".join(error) + "\n")
    # all the bugs found while writing these tests are fixed: their description is kept as a note
    if known_bug or notes:
        text = textwrap.dedent(notes or "").strip()
        if known_bug:
            text = "Bug found by this test (fixed): " + textwrap.dedent(known_bug).strip() + ("\n\n" + text if text else "")
        w("NOTES.md", text + "\n")
    if levels:
        w("levels.txt", levels + "\n")
    if log is not None:
        w("expected_log.txt", "\n".join(log) + "\n")


if os.path.isdir(ROOT):
    for entry in os.listdir(ROOT):
        if os.path.isdir(os.path.join(ROOT, entry)):
            shutil.rmtree(os.path.join(ROOT, entry))

# =========================================================================================
# sanity_check_oob: 3110e2c, cc7f1e4, e9e1f82 (OOB checks), e2c0304 (#418 buses), 5dc05e2 (#432)
# =========================================================================================
G = "sanity_check_oob"
READ_VAR = """
    pragma circom 2.2.0;
    template Main() {
        signal input i;
        signal output o;
        var a[2] = [7, 8];
        o <-- a[i];
    }
    component main = Main();
"""
case(f"{G}/runtime/read_var_index_2", READ_VAR, {"i": "2"}, flags=S3, runtime_error=OOB)
case(f"{G}/runtime/read_var_index_minus1", READ_VAR, {"i": str(P - 1)}, flags=S3, runtime_error=OOB)
case(f"{G}/correct/read_var_in_bounds", READ_VAR, {"i": "1"}, {"o": 8}, flags=S3)
case(f"{G}/correct/read_var_sanity2_no_check", READ_VAR.replace("a[i]", "a[i - 1]"), {"i": "1"}, {"o": 7})

MULTIDIM = """
    pragma circom 2.2.0;
    template Main() {
        signal input i;
        signal input j;
        signal output o;
        var a[2][3] = [[1, 2, 3], [4, 5, 6]];
        o <-- a[i][j];
    }
    component main = Main();
"""
# linear index 0*3+5 = 5 < 6 but j = 5 >= 3: each dimension must be checked on its own
case(f"{G}/runtime/multidim_inner_index", MULTIDIM, {"i": "0", "j": "5"}, flags=S3, runtime_error=OOB)
case(f"{G}/runtime/multidim_outer_index", MULTIDIM, {"i": "2", "j": "0"}, flags=S3, runtime_error=OOB)
case(f"{G}/correct/multidim_in_bounds", MULTIDIM, {"i": "1", "j": "2"}, {"o": 6}, flags=S3)

case(f"{G}/runtime/store_in_function", """
    pragma circom 2.2.0;
    function f(i) {
        var a[3] = [0, 0, 0];
        a[i] = 1;
        return a[0] + a[1] + a[2];
    }
    template Main() {
        signal input i;
        signal output o;
        o <-- f(i);
    }
    component main = Main();
""", {"i": "3"}, flags=S3, runtime_error=OOB)

case(f"{G}/runtime/store_signal", """
    pragma circom 2.2.0;
    template Main() {
        signal input idx;
        signal a[2];
        a[idx] <-- 7;
        signal output y;
        y <== idx;
    }
    component main = Main();
""", {"idx": "999"}, flags=S3, runtime_error=OOB)

BUS418 = """
    pragma circom 2.2.0;
    bus B {
        signal a[2];
    }
    template Main() {
        signal input idx;
        B b;
        b.a[idx] <-- 7;
        signal output y;
        y <== idx;
    }
    component main = Main();
"""
case(f"{G}/runtime/issue_418_bus_field_999", BUS418, {"idx": "999"}, flags=S3, runtime_error=OOB)
case(f"{G}/runtime/issue_418_bus_field_2pow30", BUS418, {"idx": str(2**30)}, flags=S3, runtime_error=OOB)

NESTED_BUS = """
    pragma circom 2.2.0;
    bus In {
        signal a[2];
    }
    bus Out {
        In x[3];
    }
    template Main() {
        signal input i;
        signal input j;
        Out o;
        o.x[i].a[j] <-- 1;
        signal output y;
        y <== i + j;
    }
    component main = Main();
"""
case(f"{G}/runtime/nested_bus_inner_index", NESTED_BUS, {"i": "1", "j": "2"}, flags=S3, runtime_error=OOB)
case(f"{G}/runtime/nested_bus_outer_index", NESTED_BUS, {"i": "3", "j": "0"}, flags=S3, runtime_error=OOB)

BUS_ARRAY = """
    pragma circom 2.2.0;
    bus B {
        signal a[2];
    }
    template Main() {
        signal input i;
        signal input j;
        signal output y;
        B b[2];
        for (var k = 0; k < 2; k++) {
            for (var m = 0; m < 2; m++) {
                b[k].a[m] <== 10 * k + m;
            }
        }
        y <-- b[i].a[j];
    }
    component main = Main();
"""
case(f"{G}/runtime/bus_array_field_index", BUS_ARRAY, {"i": "0", "j": "2"}, flags=S3, runtime_error=OOB)
case(f"{G}/correct/bus_array_in_bounds", BUS_ARRAY, {"i": "1", "j": "1"}, {"y": 11}, flags=S3)

# ---- issue 432: the check of an index with several operations used a single scratch slot
I432_1 = """
    pragma circom 2.2.0;

    template Main() {
        signal input x;
        signal output o;
        var a[2] = [7, 8];
        o <-- a[(x - 5) + (x - 4)];
        log("o =", o);
    }

    component main = Main();
"""
case(f"{G}/correct/issue_432_shape1", I432_1, {"x": "5"}, {"o": 8}, flags=S3, log=["o = 8"])
case(f"{G}/runtime/issue_432_shape1_control_x6", I432_1, {"x": "6"}, flags=S3, runtime_error=OOB)
case(f"{G}/correct/issue_432_shape2", """
    pragma circom 2.2.0;

    function f(p) {
        var a[1] = [0];
        var v = a[0 % (5 + 4)];
        return p;
    }

    template Main() {
        signal input x;
        signal output o;
        o <-- f(x);
        log("o =", o);
    }

    component main = Main();
""", {"x": "5"}, {"o": 5}, flags=S3, log=["o = 5"])
case(f"{G}/correct/issue_432_two_reads_many_ops", """
    pragma circom 2.2.0;
    template Main() {
        signal input x;
        signal output o;
        var a[2] = [10, 20];
        var b[2] = [1, 2];
        // (0*1)+0+1 = 1 and 1*1 = 1
        o <-- a[(x - 5) * (x - 4) + (x - 5) + 1] + b[(x - 4) * (x - 4)];
    }
    component main = Main();
""", {"x": "5"}, {"o": 22}, flags=S3)
case(f"{G}/correct/issue_432_store_mod_index", """
    pragma circom 2.2.0;
    template Main() {
        signal input x;
        signal output o;
        var a[3] = [0, 0, 0];
        a[(x - 3) % (x - 1)] = x;   // 1 % 3 = 1
        o <-- a[1];
    }
    component main = Main();
""", {"x": "4"}, {"o": 4}, flags=S3)
case(f"{G}/correct/issue_432_call_into_indexed_dest", """
    pragma circom 2.2.0;
    function g(y) {
        return y + 1;
    }
    template Main() {
        signal input x;
        signal output o;
        var r[3] = [0, 0, 0];
        r[(x - 4) + (x - 4)] = g(x);   // r[2] = 6
        o <-- r[2];
    }
    component main = Main();
""", {"x": "5"}, {"o": 6}, flags=S3)
case(f"{G}/correct/issue_432_nested_load_in_index", """
    pragma circom 2.2.0;
    template Main() {
        signal input x;
        signal output o;
        var b[2] = [7, 8];
        var a[2] = [10, 20];
        o <-- a[b[(x - 5) + (x - 4)] - 7];   // a[8 - 7] = 20
    }
    component main = Main();
""", {"x": "5"}, {"o": 20}, flags=S3)
case(f"{G}/correct/issue_432_intdiv_in_index", """
    pragma circom 2.2.0;
    template Main() {
        signal input x;
        signal output o;
        var a[4] = [1, 2, 3, 4];
        o <-- a[((x * x - 16) \\ 3) + (x - 5)];   // 9 \\ 3 + 0 = 3
    }
    component main = Main();
""", {"x": "5"}, {"o": 4}, flags=S3)
LOOP_IDX = """
    pragma circom 2.2.0;
    template Main() {
        signal input x;
        signal output o;
        var a[3] = [1, 2, 3];
        var acc = 0;
        for (var k = 0; k < 3; k++) {
            acc += a[(x - 5) + k];
        }
        o <-- acc;
    }
    component main = Main();
"""
case(f"{G}/correct/index_in_known_loop", LOOP_IDX, {"x": "5"}, {"o": 6}, flags=S3)
case(f"{G}/runtime/index_in_known_loop_oob", LOOP_IDX, {"x": "6"}, flags=S3, runtime_error=OOB)

# ---- gaps found reviewing the code
SUB_OUT = """
    pragma circom 2.2.0;
    template T() {
        signal output out[2];
        out[0] <== 1;
        out[1] <== 2;
    }
    template Main() {
        signal input i;
        signal output o;
        component t = T();
        o <-- t.out[i];
    }
    component main = Main();
"""
case(f"{G}/runtime/subcomponent_output_index", SUB_OUT, {"i": "5"}, flags=S3, runtime_error=OOB,
     known_bug="""
        Accesses to signals of subcomponents (t.out[i]) are not bounds-checked:
        compiler/src/intermediate_representation/translate.rs (build_signal_location) computes the
        checks for the Uniform case and drops them; the Mixed/Mapped case never creates them.
     """)
case(f"{G}/runtime/subcomponent_bus_field_index", """
    pragma circom 2.2.0;
    bus B {
        signal a[2];
    }
    template T() {
        output B() ob;
        ob.a[0] <== 1;
        ob.a[1] <== 2;
    }
    template Main() {
        signal input idx;
        signal output y;
        component t = T();
        y <-- t.ob.a[idx];
    }
    component main = Main();
""", {"idx": "3"}, flags=S3, runtime_error=OOB,
     known_bug="Bus fields of subcomponents (t.ob.a[idx]) are not bounds-checked (same cause as subcomponent_output_index).")
case(f"{G}/runtime/index_2pow32", READ_VAR, {"i": str(2**32)}, flags=S3, runtime_error=OOB,
     known_bug="""
        Fr_toInt keeps the low 32 bits in wasm, so i = 2^32 reads a[0] without error.
        In C++ (bn128) Fr_toInt aborts without the out-of-bounds message.
     """)
case(f"{G}/runtime/index_mul_wraps_32bits", READ_VAR.replace("a[i]", "a[4 * i]"), {"i": str(2**30)}, flags=S3,
     runtime_error=OOB,
     known_bug="Index arithmetic is done in 32 bits (AddAddress/MulAddress): 4 * 2^30 wraps to 0 and passes the check.")

# =========================================================================================
# division_by_zero: d1716db (/ and \ checks at sanity_check 3), fa4ea6b (% 0 at compile time)
# =========================================================================================
G = "division_by_zero"
DIV = """
    pragma circom 2.2.0;
    template Main() {
        signal input a;
        signal input b;
        signal output o;
        o <-- a OP b;
    }
    component main = Main();
"""
case(f"{G}/runtime/div_signal", DIV.replace("OP", "/"), {"a": "3", "b": "0"}, flags=S3, runtime_error=DIVZ)
case(f"{G}/runtime/intdiv_signal", DIV.replace("OP", "\\"), {"a": "3", "b": "0"}, flags=S3, runtime_error=DIVZ)
case(f"{G}/runtime/mod_signal", DIV.replace("OP", "%"), {"a": "3", "b": "0"}, flags=S3, runtime_error=DIVZ,
     known_bug="""
        % is not checked at --sanity_check 3 (only / and \\ are): wasm traps with
        "RuntimeError: divide by zero" and C++ crashes inside GMP (SIGFPE).
     """)
case(f"{G}/correct/div_sanity2_gives_zero", DIV.replace("OP", "/"), {"a": "3", "b": "0"}, {"o": 0})
case(f"{G}/correct/div_nonzero", DIV.replace("OP", "/"), {"a": "6", "b": "3"}, {"o": 2}, flags=S3)
case(f"{G}/correct/intdiv_nonzero", DIV.replace("OP", "\\"), {"a": "7", "b": "2"}, {"o": 3}, flags=S3)
FDIV = """
    pragma circom 2.2.0;
    function g(x, y) {
        var r = x OP y;
        return r;
    }
    template Main() {
        signal input a;
        signal input b;
        signal output o;
        o <-- g(a, b);
    }
    component main = Main();
"""
case(f"{G}/runtime/div_in_function", FDIV.replace("OP", "/"), {"a": "3", "b": "0"}, flags=S3, runtime_error=DIVZ)
case(f"{G}/runtime/intdiv_in_function", FDIV.replace("OP", "\\"), {"a": "3", "b": "0"}, flags=S3,
     runtime_error=DIVZ)
ISZERO = """
    pragma circom 2.2.0;
    template Main() {
        signal input a;
        signal output out;
        signal inv;
        inv <-- a != 0 ? 1 / a : 0;
        out <== -a * inv + 1;
        a * out === 0;
    }
    component main = Main();
"""
case(f"{G}/correct/iszero_guard_zero", ISZERO, {"a": "0"}, {"out": 1}, flags=S3)
case(f"{G}/correct/iszero_guard_nonzero", ISZERO, {"a": "5"}, {"out": 0}, flags=S3)
case(f"{G}/correct/if_guard_zero", """
    pragma circom 2.2.0;
    template Main() {
        signal input a;
        signal input b;
        signal output o;
        if (b != 0) {
            o <-- a / b;
        } else {
            o <-- 0;
        }
    }
    component main = Main();
""", {"a": "3", "b": "0"}, {"o": 0}, flags=S3)
nested = "x[0]"
for k in range(1, 17):
    nested = f"x[{k}] / ({nested})"
case(f"{G}/correct/nested_divisions_depth16", f"""
    pragma circom 2.2.0;
    template Main() {{
        signal input x[17];
        signal output o;
        o <-- {nested};
    }}
    component main = Main();
""", {"x": ["1"] * 17}, {"o": 1}, flags=S3, levels="1",
     notes="The divisor of every / is evaluated twice in wasm (once for the zero check): watch compile time and wasm size.")

MOD_HEAD = "pragma circom 2.1.0;\n"
DIVZERO_ERR = ["error[T3001]", "Division by zero"]
case(f"{G}/compile_error/issue_415_mod_zero_signal", """
    pragma circom 2.1.0;
    template Main() { signal output out; out <-- 17 % 0; }
    component main = Main();
""", error=DIVZERO_ERR, levels="0")
case(f"{G}/compile_error/issue_419_mod_zero_var", """
    pragma circom 2.1.0;
    template T() {
        var v = 5 % 0;
    }
    component main = T();
""", error=DIVZERO_ERR, levels="0")
case(f"{G}/compile_error/mod_by_prime", f"""
    pragma circom 2.1.0;
    template T() {{
        var v = 5 % {P};
    }}
    component main = T();
""", error=DIVZERO_ERR, levels="0")
case(f"{G}/compile_error/mod_zero_through_function", """
    pragma circom 2.1.0;
    function f(x) {
        return 7 % x;
    }
    template T() {
        signal output o;
        var v = f(0);
        o <== v;
    }
    component main = T();
""", error=DIVZERO_ERR + ["->f"], levels="0")
case(f"{G}/compile_error/intdiv_zero_var", """
    pragma circom 2.1.0;
    template T() {
        var v = 5 \\ 0;
    }
    component main = T();
""", error=DIVZERO_ERR, levels="0")
case(f"{G}/compile_error/div_zero_var", """
    pragma circom 2.1.0;
    template T() {
        var v = 5 / 0;
    }
    component main = T();
""", error=DIVZERO_ERR, levels="0")

# =========================================================================================
# template_loops: 2e368af (#420)
# =========================================================================================
G = "template_loops"
LOOP_ERR = ["error[T3001]", "Found loop in template calls"]
case(f"{G}/compile_error/issue_420_mutual", """
    template A() { component b = B(); }
    template B() { component a = A(); }
    component main = A();
""", error=LOOP_ERR, levels="0")
case(f"{G}/compile_error/self_same_parameter", """
    pragma circom 2.2.0;
    template A(n) {
        signal input in;
        signal output out;
        component a = A(n);
        a.in <== in;
        out <== a.out;
    }
    component main = A(3);
""", error=LOOP_ERR, levels="0")
case(f"{G}/compile_error/three_cycle_with_parameters", """
    pragma circom 2.2.0;
    template A(n) { component b = B(n + 1); }
    template B(n) { component c = C(n - 1); }
    template C(n) { component a = A(n); }
    component main = A(1);
""", error=LOOP_ERR, levels="0")
case(f"{G}/compile_error/mutual_anonymous", """
    pragma circom 2.2.0;
    template A() {
        signal input in;
        signal output out;
        out <== B()(in);
    }
    template B() {
        signal input in;
        signal output out;
        out <== A()(in);
    }
    component main = A();
""", error=LOOP_ERR, levels="0")
case(f"{G}/compile_error/loop_inside_known_if", """
    pragma circom 2.2.0;
    template A(n) {
        signal input in;
        signal output out;
        if (n > 2) {
            component a = A(n - 1);
            a.in <== in;
            out <== a.out;
        } else {
            component a = A(n);
            a.in <== in;
            out <== a.out;
        }
    }
    component main = A(4);
""", error=LOOP_ERR, levels="0")
case(f"{G}/correct/recursion_with_base_case", """
    pragma circom 2.2.0;
    template A(n) {
        signal input in;
        signal output o;
        if (n > 0) {
            component a = A(n - 1);
            a.in <== in;
            o <== a.o + 1;
        } else {
            o <== in;
        }
    }
    component main = A(5);
""", {"in": "3"}, {"o": 8})
case(f"{G}/correct/same_template_different_parameters_in_loop", """
    pragma circom 2.2.0;
    template Leaf(k) {
        signal input in;
        signal output out;
        out <== in * k;
    }
    template Node(n) {
        signal input in;
        signal output out;
        component l[n];
        var acc = 0;
        for (var i = 0; i < n; i++) {
            l[i] = Leaf(i + 1);
            l[i].in <== in;
            acc += l[i].out;
        }
        out <== acc;
    }
    template Main() {
        signal input in;
        signal output out;
        component a = Node(3);
        component b = Node(3);
        a.in <== in;
        b.in <== a.out;
        out <== b.out;
    }
    component main = Main();
""", {"in": "2"}, {"out": 72})
case(f"{G}/correct/recursion_decreasing_input_tag", """
    pragma circom 2.2.0;
    template A() {
        signal input {maxv} in;
        signal output o;
        if (in.maxv > 0) {
            signal {maxv} t;
            t.maxv = in.maxv - 1;
            t <== in;
            component a = A();
            a.in <== t;
            o <== a.o + 1;
        } else {
            o <== in;
        }
    }
    template Main() {
        signal input x;
        signal output o;
        signal {maxv} t;
        t.maxv = 3;
        t <== x;
        component a = A();
        a.in <== t;
        o <== a.o;
    }
    component main = Main();
""", {"x": "4"}, {"o": 7})
case(f"{G}/correct/recursion_decreasing_bus_field_tag", """
    pragma circom 2.2.0;
    bus B {
        signal {maxv} v;
    }
    template A() {
        input B() in;
        signal output o;
        if (in.v.maxv > 0) {
            B() t;
            t.v.maxv = in.v.maxv - 1;
            t.v <== in.v;
            component a = A();
            a.in <== t;
            o <== a.o + 1;
        } else {
            o <== in.v;
        }
    }
    template Main() {
        signal input x;
        signal output o;
        B() t;
        t.v.maxv = 3;
        t.v <== x;
        component a = A();
        a.in <== t;
        o <== a.o;
    }
    component main = Main();
""", {"x": "4"}, {"o": 7},
     notes="""
        REGRESSION (2e368af, works with a100fae): false loop detection.
        Recursion that terminates thanks to the tag of a bus field. The instantiation name used by
        the loop detection does not include bus field tags (TODO in execute.rs, execute_template_call),
        so this may be reported as a false loop.
     """)
case(f"{G}/compile_error/growing_parameter", """
    pragma circom 2.2.0;
    template A(n) {
        signal input in;
        signal output o;
        component a = A(n + 1);
        a.in <== in;
        o <== a.o;
    }
    component main = A(0);
""", error=["error[T3001]", "Too many nested template calls"], levels="0",
     known_bug="Unbounded recursion with growing parameters is not detected (parameters never repeat): stack overflow.")

# =========================================================================================
# pragma: ea0263d
# =========================================================================================
G = "pragma"
BODY = "\ntemplate T() { signal input a; signal output b; b <== a; }\ncomponent main = T();\n"
for name, version in [("major_2pow64", "18446744073709551616.0.0"),
                      ("major_20_digits", "99999999999999999999.0.0"),
                      ("minor_20_digits", "2.99999999999999999999.0"),
                      ("patch_20_digits", "2.2.99999999999999999999")]:
    case(f"{G}/compile_error/{name}", f"pragma circom {version};" + BODY, error=["error[P1010]"], levels="0")
case(f"{G}/compile_error/major_u64_max_control", "pragma circom 18446744073709551615.0.0;" + BODY,
     error=["error[P1003]"], levels="0")
case(f"{G}/compile_error/hex_literal_without_digits", """
    pragma circom 2.2.0;
    template T() {
        signal output b;
        var x = 0x;
        b <== x;
    }
    component main = T();
""", error=["error["], levels="0",
     known_bug="'0x' without digits reaches parse_bytes(..).expect() in parser/src/lang.lalrpop and panics.")

# =========================================================================================
# shifts: d79f13b (#416, #422)
# =========================================================================================
G = "shifts"
TWO253 = 2**253
SHIFT_CASES = [  # (x, op, s, expected)
    (5, "<<", 2000000000, 0),
    (5, ">>", 2000000000, 0),
    (1, "<<", 2**30, 0),
    (1, "<<", 253, TWO253),
    (3, "<<", 253, TWO253),
    (1, "<<", 254, 0),
    (1, ">>", 254, 0),
    (TWO253 + 1, "<<", 1, 2),
    (TWO253, ">>", 253, 1),
    (P - 1, ">>", 253, 1),
    (5, "<<", P - 1, 2),          # shift by -1
    (5, ">>", P - 1, 10),
    (1, ">>", P - 253, TWO253),
    (5, "<<", P - 2000000000, 0),
    (5, "<<", (P - 1) // 2, 0),   # biggest positive shift
    (5, "<<", (P + 1) // 2, 0),   # smallest negative shift
]
n = len(SHIFT_CASES)
const_lines = "\n".join(f"        c[{i}] <-- {x} {op} {s};" for i, (x, op, s, _) in enumerate(SHIFT_CASES))
expected = {"c": [str(e) for (_, _, _, e) in SHIFT_CASES]}
case(f"{G}/correct/constant_shifts", f"""
    pragma circom 2.2.0;
    template Main() {{
        signal input dummy;
        signal output c[{n}];
{const_lines}
    }}
    component main = Main();
""", {"dummy": "0"}, expected)
case(f"{G}/correct/constant_shift_nested_1_shl_1_shl_30", """
    pragma circom 2.2.0;
    template T() {
        signal input a;
        signal output b;
        var v = 1 << (1 << 30);
        var w = 1 << (1 << 31);
        b <== a + v + w;
    }
    component main = T();
""", {"a": "3"}, {"b": 3})
rt_lines = "\n".join(f"        c[{i}] <-- x[{i}] {op} s[{i}];" for i, (_, op, _, _) in enumerate(SHIFT_CASES))
case(f"{G}/correct/runtime_shifts", f"""
    pragma circom 2.2.0;
    template Main() {{
        signal input x[{n}];
        signal input s[{n}];
        signal output c[{n}];
{rt_lines}
    }}
    component main = Main();
""", {"x": [str(x) for (x, _, _, _) in SHIFT_CASES], "s": [str(s) for (_, _, s, _) in SHIFT_CASES]}, expected,
     notes="Same table as constant_shifts but computed by the witness generator: both must agree.")
GL = [(1, "<<", 63, 2**63), (3, "<<", 63, 2**63), (1, "<<", 64, 0), (1, ">>", 64, 0),
      (5, "<<", GOLDILOCKS - 1, 2), (5, "<<", 2000000000, 0)]
case(f"{G}/correct/goldilocks_constant_shifts", f"""
    pragma circom 2.2.0;
    template Main() {{
        signal input dummy;
        signal output c[{len(GL)}];
{chr(10).join(f"        c[{i}] <-- {x} {op} {s};" for i, (x, op, s, _) in enumerate(GL))}
    }}
    component main = Main();
""", {"dummy": "0"}, {"c": [str(e) for (_, _, _, e) in GL]}, flags="--prime goldilocks")
case(f"{G}/correct/goldilocks_runtime_shifts", f"""
    pragma circom 2.2.0;
    template Main() {{
        signal input x[{len(GL)}];
        signal input s[{len(GL)}];
        signal output c[{len(GL)}];
{chr(10).join(f"        c[{i}] <-- x[{i}] {op} s[{i}];" for i, (_, op, _, _) in enumerate(GL))}
    }}
    component main = Main();
""", {"x": [str(x) for (x, _, _, _) in GL], "s": [str(s) for (_, _, s, _) in GL]},
     {"c": [str(e) for (_, _, _, e) in GL]}, flags="--prime goldilocks")

# =========================================================================================
# renaming_and_main: ddb993b (#394, #409, #398)
# =========================================================================================
G = "renaming_and_main"
UNIQUE = ["error[T3001]", "names must be unique"]
case(f"{G}/compile_error/issue_394", """
    template C(n) {
      signal input in;
      signal output out;

      if (n == 0) {
        signal input in;
        signal input in2;
        signal output out;
        out <== in + in2;
      } else {
        signal input in;
        signal input in2;
        out <== in * in2;
      }
    }

    component main {public [in,in2]} = C(0);
""", error=["error["], levels="0")
case(f"{G}/compile_error/issue_409_signal_after_block_with_component", """
    pragma circom 2.2.0;
    template Sub() {
        signal input in;
        signal output out;
        out <== in;
    }
    template Demo() {
        signal input x;
        signal output y;
        if (1 == 1) {
            signal foo <== x;
            component s = Sub();
            s.in <== foo;
            y <== s.out;
        }
        signal foo <== 2;
    }
    component main = Demo();
""", error=UNIQUE, levels="0")
case(f"{G}/compile_error/sibling_blocks_same_signal", """
    pragma circom 2.2.0;
    template T(n) {
        signal input a;
        signal output o;
        if (n == 0) {
            signal t;
            t <== a;
        }
        if (n == 0) {
            signal t;
            t <== a;
        }
        o <== a;
    }
    component main = T(0);
""", error=UNIQUE, levels="0")
case(f"{G}/compile_error/sibling_blocks_same_component", """
    pragma circom 2.2.0;
    template Sub() {
        signal input in;
        signal output out;
        out <== in;
    }
    template T() {
        signal input a;
        signal output o;
        {
            component c = Sub();
            c.in <== a;
        }
        {
            component c = Sub();
            c.in <== a;
            o <== c.out;
        }
    }
    component main = T();
""", error=UNIQUE, levels="0")
case(f"{G}/compile_error/var_shadows_signal", """
    pragma circom 2.2.0;
    template T() {
        signal input a;
        signal output x;
        x <== a;
        {
            var x = 1;
        }
    }
    component main = T();
""", error=["error["], levels="0")
case(f"{G}/correct/same_signal_name_in_if_else", """
    pragma circom 2.2.0;
    template T(n) {
        signal input a;
        signal output o;
        if (n == 0) {
            signal t;
            t <== a;
            o <== t;
        } else {
            signal t;
            t <== a * a;
            o <== t;
        }
    }
    component main = T(1);
""", {"a": "3"}, {"o": 9})
case(f"{G}/correct/same_var_name_in_sibling_blocks", """
    pragma circom 2.2.0;
    template T() {
        signal input a;
        signal output o;
        var acc = 0;
        {
            var t = 2;
            acc += t;
        }
        {
            var t = 3;
            acc += t;
        }
        o <== a * acc;
    }
    component main = T();
""", {"a": "3"}, {"o": 15})
MAIN_TEMPLATES = """
    pragma circom 2.2.0;
    bus B(n) {
        signal x[n];
    }
    template Main(n) {
        signal input a;
        signal output b;
        b <== a * n;
    }
"""
for name, expr in [("issue_398_anonymous_param", "Main( Main(4)() )"),
                   ("issue_398_parallel_anonymous_param", "Main( parallel Main(4)() )"),
                   ("issue_398_bus_anonymous_param", "Main( B(4)() )"),
                   ("issue_398_expression_with_anonymous", "Main( 12 + -f(Main(12)()) )"),
                   ("main_template_call_param", "Main( Main(4) )"),
                   ("main_bus_call_param", "Main( B(4) )"),
                   ("main_tuple_param", "Main( (1, 2) )")]:
    src = MAIN_TEMPLATES + "    function f(x) { return x; }\n    component main = " + expr + ";\n"
    case(f"{G}/compile_error/{name}", src, error=["error["], levels="0")
case(f"{G}/compile_error/bus_with_conditional_redeclaration", """
    pragma circom 2.2.0;
    bus B(n) {
        signal a;
        if (n == 0) {
            signal a;
        }
    }
    template T() {
        signal input x;
        signal output y;
        B(0) b;
        b.a <== x;
        y <== b.a;
    }
    component main = T();
""", error=["error[T2052]"], levels="0")
case(f"{G}/compile_error/bus_duplicated_field", """
    pragma circom 2.2.0;
    bus B {
        signal a;
        signal a;
    }
    template T() {
        signal input x;
        signal output y;
        B b;
        b.a <== x;
        y <== b.a;
    }
    component main = T();
""", error=["error["], levels="0")

# =========================================================================================
# while_inside_if: 51bcaa8 (#437)
# =========================================================================================
G = "while_inside_if"
I437 = """
    pragma circom 2.2.0;

    template Main() {
        signal input x;
        signal output h;
        if (x != 0) {
            if (x != 6) { } else { for (var w = 0; w < 2; w++) { } }
            h <-- 1;
        } else {
            h <-- 2;
        }
    }

    component main = Main();
"""
case(f"{G}/correct/issue_437_x6", I437, {"x": "6"}, {"h": 1})
case(f"{G}/correct/issue_437_x0", I437, {"x": "0"}, {"h": 2})
case(f"{G}/correct/issue_437_while_variant", """
    pragma circom 2.2.0;
    template Main() {
        signal input x;
        signal output h;
        var w = 0;
        if (x != 0) {
            if (x != 6) { } else { while (w < 1) { w++; } }
            h <-- 1;
        } else {
            h <-- 2;
        }
    }
    component main = Main();
""", {"x": "0"}, {"h": 2})
LOOPS_BOTH = """
    pragma circom 2.2.0;
    template Main() {
        signal input x;
        signal output h;
        if (x != 0) {
            for (var i = 0; i < 1; i++) { h <-- 1; }
        } else {
            for (var j = 0; j < 1; j++) { h <-- 2; }
        }
    }
    component main = Main();
"""
LOOPS_KB = """
    Signal assigned inside a known loop in both branches of an unknown if: reported as
    "Signal has been already assigned" (the same line as previous and current assignment).
    Fails with v2.2.3, a100fae and HEAD: 51bcaa8 (#437) does not cover it.
"""
case(f"{G}/correct/assignment_inside_loops_in_both_branches_x0", LOOPS_BOTH, {"x": "0"}, {"h": 2}, known_bug=LOOPS_KB)
case(f"{G}/correct/assignment_inside_loops_in_both_branches_x5", LOOPS_BOTH, {"x": "5"}, {"h": 1}, known_bug=LOOPS_KB)
case(f"{G}/correct/deep_nesting_known_loops", """
    pragma circom 2.2.0;
    template Main() {
        signal input x;
        signal input y;
        signal output h;
        var acc = 0;
        if (x != 0) {
            for (var i = 0; i < 3; i++) {
                if (y != 0) {
                    for (var j = 0; j < 3; j++) {
                        while (acc < 4) { acc++; }
                    }
                } else {
                    for (var k = 0; k < 2; k++) { acc += 2; }
                }
            }
            h <-- acc;
        } else {
            var t = 0;
            while (t < 3) { t++; }
            h <-- t;
        }
    }
    component main = Main();
""", {"x": "1", "y": "0"}, {"h": 12})
case(f"{G}/compile_error/assignment_after_if_else", """
    pragma circom 2.2.0;
    template Main() {
        signal input x;
        signal output h;
        if (x != 0) {
            for (var i = 0; i < 3; i++) { }
            h <-- 1;
        } else {
            h <-- 2;
        }
        h <-- 3;
    }
    component main = Main();
""", error=["error[T3001]", "already assigned"], levels="0")
case(f"{G}/compile_error/assignment_in_branches_inside_known_loop", """
    pragma circom 2.2.0;
    template Main() {
        signal input x;
        signal output h;
        for (var i = 0; i < 2; i++) {
            if (x != 0) {
                h <-- 1;
            } else {
                h <-- 2;
            }
        }
    }
    component main = Main();
""", error=["error[T3001]", "already assigned"], levels="0")
case(f"{G}/compile_error/bus_field_in_loop_then_whole_bus", """
    pragma circom 2.2.0;
    bus P {
        signal f[2];
    }
    template Main() {
        signal input a;
        signal output o;
        P b;
        P other;
        other.f[0] <== a;
        other.f[1] <== a;
        for (var i = 0; i < 2; i++) {
            b.f[i] <== a;
        }
        b <== other;
        o <== b.f[0];
    }
    component main = Main();
""", error=["error[T3001]"], levels="0")

# =========================================================================================
# size_zero: 2d4813c (#436), 3a9efd5 (C++ code for assignments of size 0)
# =========================================================================================
G = "size_zero"
I436 = """
    pragma circom 2.2.0;

    template G(K) {
        signal input x;
        signal output out;
        signal s[0];
        out <== x;
    }

    template Main() {
        signal input a;
        signal output o[2];
        component g[2];
        for (var i = 0; i < 2; i++) {
            g[i] = G(i);
            g[i].x <== a;
            o[i] <== g[i].out;
        }
    }

    component main = Main();
"""
case(f"{G}/correct/issue_436", I436, {"a": "7"}, {"o": [7, 7]})
case(f"{G}/correct/issue_436_sanity3", I436, {"a": "7"}, {"o": [7, 7]}, flags=S3)
case(f"{G}/correct/issue_436_output_size0", I436.replace("signal s[0];", "signal output z[0];"),
     {"a": "7"}, {"o": [7, 7]})
case(f"{G}/correct/mixed_output_size0_2d", """
    pragma circom 2.2.0;
    template G(K) {
        signal input x;
        signal output z[K][3];
        signal output out;
        for (var i = 0; i < K; i++) {
            for (var j = 0; j < 3; j++) {
                z[i][j] <== x + i + j;
            }
        }
        out <== x;
    }
    template Main() {
        signal input a;
        signal output o[2];
        signal output w;
        component g[2];
        for (var i = 0; i < 2; i++) {
            g[i] = G(2 * i);
            g[i].x <== a;
            o[i] <== g[i].out;
        }
        w <== g[1].z[1][2];
    }
    component main = Main();
""", {"a": "5"}, {"o": [5, 5], "w": 8})
MIXED_IN = """
    pragma circom 2.2.0;
    template G(K) {
        signal input x;
        signal input in[K];
        signal output out;
        var s = 0;
        for (var i = 0; i < K; i++) {
            s += in[i];
        }
        out <== x + s;
        log("G", K);
    }
    template Main() {
        signal input a;
        signal input e1[1];
        signal output o[2];
        signal e0[0];
        component g[2];
        g[0] = G(0);
        g[1] = G(1);
        BODY
        o[0] <== g[0].out;
        o[1] <== g[1].out;
    }
    component main = Main();
"""
for order, body in [("size0_store_last", "g[0].x <== a; g[1].x <== a; g[0].in <== e0; g[1].in <== e1;"),
                    ("size0_store_first", "g[0].in <== e0; g[1].in <== e1; g[0].x <== a; g[1].x <== a;")]:
    for sc in ("2", "3"):
        case(f"{G}/correct/mixed_input_{order}_sanity{sc}", MIXED_IN.replace("BODY", body),
             {"a": "3", "e1": ["4"]}, {"o": [3, 7]}, flags=f"--sanity_check {sc}", log=["G 0", "G 1"],
             known_bug=None if order == "size0_store_first" else """
                C++ runs g[0] = G(0) twice when its size-0 input is stored last (wasm runs it once):
                the store gets StatusInput Last/Unknown although it does not decrement the counter.
                Fails with v2.2.3 too (there it panics, #436).
             """)
case(f"{G}/correct/mixed_input_size0_in_loop", """
    pragma circom 2.2.0;
    template G(K) {
        signal input x;
        signal input in[K];
        signal output out;
        var s = 0;
        for (var i = 0; i < K; i++) {
            s += in[i];
        }
        out <== x + s;
        log("G", K);
    }
    template Main() {
        signal input a;
        signal input b;
        signal output o[3];
        component g[3];
        for (var i = 0; i < 3; i++) {
            g[i] = G(i);
            g[i].x <== a;
            for (var j = 0; j < i; j++) {
                g[i].in[j] <== b;
            }
            o[i] <== g[i].out;
        }
    }
    component main = Main();
""", {"a": "3", "b": "4"}, {"o": [3, 7, 11]}, flags=S3, log=["G 0", "G 1", "G 2"])
SINGLE0 = """
    pragma circom 2.2.0;
    template G(K) {
        signal input x;
        signal input in[K];
        signal output out;
        out <== x;
        log("run");
    }
    template Main() {
        signal input a;
        signal output o;
        signal empty[0];
        component c = G(0);
        BODY
        o <== c.out;
    }
    component main = Main();
"""
case(f"{G}/correct/single_size0_store_last", SINGLE0.replace("BODY", "c.x <== a; c.in <== empty;"),
     {"a": "3"}, {"o": 3}, log=["run"])
case(f"{G}/correct/single_size0_store_first", SINGLE0.replace("BODY", "c.in <== empty; c.x <== a;"),
     {"a": "3"}, {"o": 3}, log=["run"])
case(f"{G}/correct/parallel_template_output_size0", """
    pragma circom 2.2.0;
    template parallel P(n) {
        signal input a[n];
        signal input b;
        signal output z[n];
        signal output o;
        z <== a;
        o <== b + 1;
    }
    template Main() {
        signal input b;
        signal output o;
        component p = P(0);
        p.b <== b;
        o <== p.o;
    }
    component main = Main();
""", {"b": "1"}, {"o": 2},
     notes="""
        REGRESSION (3a9efd5, works with v2.2.3). C++: the store of size 0 into the output of a parallel template opens a block that is never
        closed (code_producers store_bucket.rs: the '}' is only emitted in the size != 0 branches).
     """)
case(f"{G}/correct/bus_with_size0_field", """
    pragma circom 2.2.0;
    bus B {
        signal a[0];
        signal x;
    }
    template Main() {
        signal input in;
        signal output o;
        B t;
        t.x <== in;
        o <== t.x;
    }
    component main = Main();
""", {"in": "5"}, {"o": 5},
     known_bug="Same division by zero as #436 but for bus fields: compiler/src/circuit_design/build.rs get_info_buses.")

# =========================================================================================
# inline_switch: a22aeaf (#435)
# =========================================================================================
G = "inline_switch"
G_ASSERT = """
    function g(a, b) {
        assert(b != 0);
        return a % b;
    }
"""
I435 = """
    pragma circom 2.1.0;

    function g(a, b) {
        assert(b != 0);
        return a % b;
    }

    template Main() {
        signal input a;
        signal input b;
        signal output y;
        y <-- b != 0 ? g(a, b) : 7;
        log("y =", y);
    }

    component main = Main();
"""
case(f"{G}/correct/issue_435_b0", I435, {"a": "5", "b": "0"}, {"y": 7}, log=["y = 7"])
case(f"{G}/correct/issue_435_b3", I435, {"a": "5", "b": "3"}, {"y": 2}, log=["y = 2"])
I435U = I435.replace("y <-- b != 0 ? g(a, b) : 7;", "if (b != 0) y <-- g(a, b) + 1; else y <-- 7;")
case(f"{G}/correct/issue_435_unbraced_if_b0", I435U, {"a": "5", "b": "0"}, {"y": 7})
case(f"{G}/correct/issue_435_unbraced_if_b3", I435U, {"a": "5", "b": "3"}, {"y": 3})
case(f"{G}/correct/issue_435_sanity3", I435, {"a": "5", "b": "0"}, {"y": 7}, flags=S3)
case(f"{G}/correct/false_arm_calls_guarded_function", f"""
    pragma circom 2.2.0;
    {G_ASSERT}
    template Main() {{
        signal input a;
        signal input b;
        signal output y;
        y <-- b == 0 ? 7 : g(a, b);
    }}
    component main = Main();
""", {"a": "5", "b": "0"}, {"y": 7})
case(f"{G}/correct/both_arms_call_guarded_function", f"""
    pragma circom 2.2.0;
    {G_ASSERT}
    template Main() {{
        signal input a;
        signal input b;
        signal output y;
        y <-- b != 0 ? g(a, b) : g(a, b + 1);
    }}
    component main = Main();
""", {"a": "5", "b": "0"}, {"y": 0})
case(f"{G}/correct/ternary_with_call_in_known_loop", f"""
    pragma circom 2.2.0;
    {G_ASSERT}
    template Main() {{
        signal input a;
        signal input b;
        signal output y;
        var acc = 0;
        for (var i = 0; i < 3; i++) {{
            acc += b != 0 ? g(a + i, b) : 7;
        }}
        y <-- acc;
    }}
    component main = Main();
""", {"a": "5", "b": "0"}, {"y": 21})
case(f"{G}/correct/ternary_in_array_index", """
    pragma circom 2.2.0;
    template Main() {
        signal input b;
        signal output o;
        var arr[2] = [10, 20];
        o <-- arr[b != 0 ? 1 : 0];
    }
    component main = Main();
""", {"b": "0"}, {"o": 10}, flags=S3)
case(f"{G}/correct/ternary_call_in_condition", """
    pragma circom 2.2.0;
    function g2(x) {
        assert(x != 0);
        return x - 1;
    }
    template Main() {
        signal input a;
        signal output y;
        y <-- (a != 0 ? g2(a) : 0) != 0 ? 1 : 2;
    }
    component main = Main();
""", {"a": "0"}, {"y": 2})
NESTED_KB = """
    REGRESSION (a22aeaf): compiles with v2.2.3 / a100fae, panics at HEAD.
    a22aeaf stores the statements lifted from each arm (inits_true/inits_false) in blocks that are not
    lowered by the sugar cleaner (map_substitutions / rhe_array_case), so a nested switch or an array
    literal reaches translate.rs and hits unreachable!("This expression is syntactic sugar").
"""
case(f"{G}/correct/nested_ternary", """
    pragma circom 2.2.0;
    template Main() {
        signal input a;
        signal input b;
        signal output y;
        y <-- a > 2 ? (b > 2 ? 1 : 2) : 3;
    }
    component main = Main();
""", {"a": "3", "b": "1"}, {"y": 2}, notes=NESTED_KB)
case(f"{G}/correct/nested_ternary_in_function_return", f"""
    pragma circom 2.2.0;
    {G_ASSERT}
    function f(a, b) {{
        return a > 0 ? (b > 0 ? g(a, b) : 7) : 9;
    }}
    template Main() {{
        signal input x;
        signal input z;
        signal output o;
        o <-- f(x, z);
    }}
    component main = Main();
""", {"x": "1", "z": "0"}, {"o": 7}, notes=NESTED_KB)
case(f"{G}/correct/array_literal_in_arm", """
    pragma circom 2.2.0;
    function s(v) {
        return v[0] + v[1];
    }
    template Main() {
        signal input a;
        signal input b;
        signal input c;
        signal output y;
        y <-- c != 0 ? s([a, b]) : 0;
    }
    component main = Main();
""", {"a": "2", "b": "3", "c": "1"}, {"y": 5}, notes=NESTED_KB)
case(f"{G}/correct/unbraced_if_with_ternary", f"""
    pragma circom 2.2.0;
    {G_ASSERT}
    template Main() {{
        signal input a;
        signal input b;
        signal output y;
        if (b != 0) y <-- (a > 1 ? g(a, b) : 1) + 1; else y <-- 3;
    }}
    component main = Main();
""", {"a": "0", "b": "0"}, {"y": 3}, notes=NESTED_KB)
case(f"{G}/correct/unbraced_else_if_with_call", """
    pragma circom 2.2.0;
    function h(a) {
        assert(a != 0);
        return a;
    }
    template Main() {
        signal input a;
        signal input b;
        signal output y;
        if (b != 0) y <-- 1; else if (h(a) > 0) y <-- 2; else y <-- 3;
    }
    component main = Main();
""", {"a": "0", "b": "5"}, {"y": 1})

# =========================================================================================
# computed_analysis: 6c3a24a (#434)
# =========================================================================================
G = "computed_analysis"
I434 = """
    pragma circom 2.1.0;

    template Main() {
        signal input a;
        signal output h[2];
        var v = 5;
        for (var i = 0; i < 2; i++) {
            h[i] <-- v != 0 ? v : 7;
            v = a;
        }
        log("h[0] =", h[0], " h[1] =", h[1]);
    }

    component main = Main();
"""
case(f"{G}/correct/issue_434_stale_arm", I434, {"a": "2"}, {"h": [5, 2]}, log=["h[0] = 5  h[1] = 2"])
case(f"{G}/correct/issue_434_guarded_division", """
    pragma circom 2.1.0;

    template Main() {
        signal input a;
        signal h[2];
        signal s[2];
        signal t[2];
        var v = 5;
        for (var i = 0; i < 2; i++) {
            h[i] <-- (v - 3) != 0 ? 1 / (v - 3) : 0;
            s[i] <== 1 - (v - 3) * h[i];
            (v - 3) * s[i] === 0;
            t[i] <== a * a;
            v = t[i];
        }
    }

    component main = Main();
""", {"a": "2"})
case(f"{G}/correct/issue_434_if_variant", """
    pragma circom 2.1.0;
    template Main() {
        signal input a;
        signal output h[2];
        var v = 5;
        for (var i = 0; i < 2; i++) {
            var r = 7;
            if (v != 0) { r = v; }
            h[i] <-- r;
            v = a;
        }
    }
    component main = Main();
""", {"a": "2"}, {"h": [5, 2]})
case(f"{G}/correct/known_false_then_unknown", """
    pragma circom 2.2.0;
    template Main() {
        signal input a;
        signal output h[3];
        var v = 5;
        for (var i = 0; i < 3; i++) {
            h[i] <-- v != 0 ? v : 7;
            if (i == 0) { v = 0; } else { v = a; }
        }
    }
    component main = Main();
""", {"a": "2"}, {"h": [5, 7, 2]})
case(f"{G}/correct/nested_loops_unknown_inner_condition", """
    pragma circom 2.2.0;
    template Main() {
        signal input a;
        signal input n;
        signal output o;
        var v = 3;
        var acc = 0;
        for (var i = 0; i < 2; i++) {
            var j = 0;
            while (j < n) {
                acc = acc + (j == 0 ? v : 2 * v);
                j++;
            }
            v = a;
        }
        o <-- acc;
    }
    component main = Main();
""", {"a": "5", "n": "2"}, {"o": 24})
case(f"{G}/correct/unknown_loop_accumulates_call", """
    pragma circom 2.2.0;
    function g(x) {
        return x;
    }
    template Main() {
        signal input n;
        signal output o;
        var i = 0;
        var s = 0;
        while (i < n) {
            s = s + g(i);
            i++;
        }
        o <-- s;
    }
    component main = Main();
""", {"n": "3"}, {"o": 3},
     notes="Calls are exempt from the 'inside unknown loop' rule of 6c3a24a: g(i) may be folded to g(0).")
LOOP_INST_KB = """
    REGRESSION (6c3a24a): works with a22aeaf. inside_unknown_loop is set for every loop (even with known conditions) and is
    not reset when a template is instantiated, so expressions of templates instantiated inside a loop are
    not considered computed and their array sizes are rejected (T2033 Invalid array size).
    Breaks circomlib (escalarmulfix, sha256, poseidon, pedersen, eddsa, ...).
"""
case(f"{G}/correct/template_instantiated_in_loop", """
    pragma circom 2.2.0;
    template T(n) {
        signal input e[n * 3];
        signal output out;
        var s = 0;
        for (var i = 0; i < n * 3; i++) {
            s += e[i];
        }
        out <== s;
    }
    template M() {
        signal input a;
        signal output o[2];
        component c[2];
        for (var k = 0; k < 2; k++) {
            c[k] = T(2);
            for (var i = 0; i < 6; i++) {
                c[k].e[i] <== a;
            }
            o[k] <== c[k].out;
        }
    }
    component main = M();
""", {"a": "2"}, {"o": [12, 12]}, notes=LOOP_INST_KB)
case(f"{G}/correct/template_instantiated_in_loop_local_size", """
    pragma circom 2.2.0;
    template T(n) {
        signal input in;
        signal output out;
        var m = n + 1;
        signal acc[m];
        acc[0] <== in;
        for (var i = 1; i < m; i++) {
            acc[i] <== acc[i - 1] * in;
        }
        out <== acc[m - 1];
    }
    template M() {
        signal input a;
        signal output o[3];
        component c[3];
        var i = 0;
        while (i < 3) {
            c[i] = T(i);
            c[i].in <== a;
            o[i] <== c[i].out;
            i++;
        }
    }
    component main = M();
""", {"a": "2"}, {"o": [2, 4, 8]}, notes=LOOP_INST_KB)
case(f"{G}/correct/bus_tag_in_loop_condition", """
    pragma circom 2.2.0;
    bus S2() {
        signal {a} aux[1];
    }
    bus S() {
        S2 {b} aux[1];
    }
    template A() {
        input S() {c} inter[1];
        signal output o;
        var n = 0;
        for (var i = 0; i < inter.c; i++) {
            n += 1;
        }
        o <== inter[0].aux[0].aux[0] * n;
    }
    template B() {
        signal input x;
        signal output y;
        component a[1];
        a[0] = A();
        signal {a} anda;
        anda.a = 5;
        anda <== x;
        S2() {b} p2;
        p2.b = 4;
        S() {c} p;
        p.c = 3;
        p2.aux[0] <== anda;
        p.aux[0] <== p2;
        a[0].inter[0] <== p;
        y <== a[0].o;
    }
    component main = B();
""", {"x": "2"}, {"y": 6},
     notes="REGRESSION (6c3a24a, works with a22aeaf). Reduced from tags_2.2/outputs/circuit: since 6c3a24a the tag access in the loop condition is not folded and the HIR merger panics (merger.rs:663, unwrap on None).")
case(f"{G}/correct/factorial_ternary_recursion", """
    pragma circom 2.2.0;
    function f(n) {
        return n == 0 ? 1 : n * f(n - 1);
    }
    template Main() {
        signal input x;
        signal output o;
        o <-- f(x);
    }
    component main = Main();
""", {"x": "3"}, {"o": 6},
     notes="REGRESSION (6c3a24a, works with a22aeaf): 6c3a24a executes both arms of a switch with unknown condition at compile time: unbounded recursion.")
case(f"{G}/correct/guard_with_known_false_part", """
    pragma circom 2.2.0;
    template Main() {
        signal input x[3];
        signal input en;
        signal output out[3];
        for (var i = 0; i < 3; i++) {
            out[i] <-- (i > 0 && en == 1) ? x[i - 1] : 0;
        }
    }
    component main = Main();
""", {"x": ["1", "2", "3"], "en": "1"}, {"out": [0, 1, 2]},
     notes="REGRESSION (6c3a24a, works with v2.2.3 and a22aeaf): at i = 0 the condition is unknown (0 && unknown is not folded), so executing both arms reads x[-1].")
case(f"{G}/correct/untaken_arm_with_failing_assert", """
    pragma circom 2.2.0;
    function g(x) {
        assert(x != 0);
        return x;
    }
    template Main() {
        signal input s;
        signal output h;
        h <-- s != 0 ? g(0) : 1;
    }
    component main = Main();
""", {"s": "0"}, {"h": 1},
     notes="REGRESSION (6c3a24a, works with a22aeaf). Design decision: should a failing assert in an arm that is not taken be a compile error?")

# =========================================================================================
# known_bugs: open issues not addressed by any commit
# =========================================================================================
G = "sugar_lowering"
case(f"{G}/correct/issue_431_swap", """
    pragma circom 2.1.0;

    template Main() {
        signal input a;
        signal input b;
        signal output o1;
        signal output o2;
        var x[2] = [a, b];
        x = [x[1], x[0]];
        o1 <== x[0] * a;
        o2 <== x[1] * a;
        log("o1 =", o1, " o2 =", o2);
    }

    component main = Main();
""", {"a": "3", "b": "4"}, {"o1": 12, "o2": 9}, known_bug="#431: x = [x[1], x[0]] is lowered element by element without a temporary.")
case(f"{G}/correct/issue_431_swap_in_function", """
    pragma circom 2.1.0;
    function sw(a, b) {
        var x[2] = [a, b];
        x = [x[1], x[0]];
        return x[0] * 10 + x[1];
    }
    template Main() {
        signal input a;
        signal input b;
        signal output h;
        signal output k;
        h <-- sw(a, b);
        k <-- sw(1, 2);
    }
    component main = Main();
""", {"a": "3", "b": "4"}, {"h": 43, "k": 21}, known_bug="#431")
I433 = """
    pragma circom 2.1.0;

    function g(x) {
        return x;
    }

    function f(n) {
        var i = 0;
        var s = 0;
        while (g(i) < n) {
            s += 10;
            i++;
            if (i > 5) {
                return 1000 + s;   // only here to bound the loop
            }
        }
        return s;
    }

    template Main() {
        signal input n;
        signal output o;
        signal output k;
        o <-- f(n);
        k <-- f(3);
        log("o =", o, " k =", k);
    }

    component main = Main();
"""
case(f"{G}/correct/issue_433_while_call_condition", I433, {"n": "3"}, {"o": 30, "k": 30},
     known_bug="#433: the call in the while condition is lifted once before the loop (extend_while).")
case(f"{G}/correct/issue_433_for_call_condition", """
    pragma circom 2.1.0;
    function g(x) {
        return x;
    }
    function f(n) {
        var s = 0;
        for (var i = 0; g(i) < n; i++) {
            s += 10;
            if (i > 4) {
                return 1000 + s;
            }
        }
        return s;
    }
    template Main() {
        signal input n;
        signal output o;
        o <-- f(n);
    }
    component main = Main();
""", {"n": "3"}, {"o": 30}, known_bug="#433")
case(f"{G}/correct/issue_433_template_while_call", """
    pragma circom 2.2.0;
    function g(x) {
        return x;
    }
    template Main() {
        signal input n;
        signal output o;
        var i = 0;
        var s = 0;
        while (g(i) < n && i < 6) {
            s += 10;
            i++;
        }
        o <-- s;
    }
    component main = Main();
""", {"n": "3"}, {"o": 30}, known_bug="#433 at template level (also: calls are folded inside unknown loops, 6c3a24a).")
case(f"{G}/correct/unbraced_while_body_call", """
    pragma circom 2.2.0;
    function g(x) {
        return x + 1;
    }
    function f(n) {
        var s = 0;
        while (s < n) s = s + g(s);
        return s;
    }
    template Main() {
        signal input n;
        signal output o;
        o <-- f(n);
    }
    component main = Main();
""", {"n": "5"}, {"o": 7}, known_bug="The call in an unbraced while body is lifted before the loop (extend_while).")

# =========================================================================================
# Harder variants of the fixes done after the first run of these tests
# =========================================================================================
G = "inline_switch"
TERNARY_MIX = """
    pragma circom 2.2.0;
    function g(a, b) { assert(b != 0); return a % b; }
    function f(a, b) {
        if (a > 5) return b > 0 ? (a > 7 ? g(a, b) : 1) : 2;
        else return a == 0 ? 3 : (b == 0 ? 4 : g(b, a));
    }
    function arr(c, a, b) {
        var v[2] = c != 0 ? [a, b] : [b, a];
        return v[0] * 10 + v[1];
    }
    template Main() {
        signal input a;
        signal input b;
        signal input c;
        signal output o[6];
        o[0] <-- a > 2 ? (b > 2 ? (c > 2 ? 1 : 2) : 3) : 4;
        o[1] <-- f(a, b);
        o[2] <-- arr(c, a, b);
        var t = c != 0 ? (b != 0 ? g(a, b) : 7) : 9;
        o[3] <-- t;
        log("t", c != 0 ? (b != 0 ? g(a, b) : 7) : 9);
        assert(c != 0 ? t == 7 || b != 0 : t == 9);
        o[4] <-- c != 0 ? g(a, (b != 0 ? b : 1)) : 0;
        var acc = 0;
        for (var i = 0; i < 3; i++) {
            if (b != 0) acc += i > 0 ? g(a + i, b) : 100; else acc += i;
        }
        o[5] <-- acc;
    }
    component main = Main();
"""
case(f"{G}/correct/ternary_mix_1", TERNARY_MIX, {"a": "8", "b": "0", "c": "1"}, {"o": [3, 2, 80, 7, 0, 3]}, log=["t 7"])
case(f"{G}/correct/ternary_mix_2", TERNARY_MIX, {"a": "9", "b": "4", "c": "0"}, {"o": [2, 1, 49, 9, 0, 105]}, log=["t 9"])
case(f"{G}/correct/ternary_as_log_and_assert_argument", """
    pragma circom 2.2.0;
    template Main() {
        signal input c;
        signal output o;
        log(c != 0 ? 1 : 2);
        log("v", c != 0 ? c : 5);
        assert(c != 0 ? c == 3 : 1);
        o <-- c;
    }
    component main = Main();
""", {"c": "3"}, {"o": 3}, log=["1", "v 3"])

G = "sanity_check_oob"
MIXED_OUT = """
    pragma circom 2.2.0;
    template G(K) {
        signal input x;
        signal output out[2];
        signal aux[K];
        out[0] <== x;
        out[1] <== x + K;
    }
    template Main() {
        signal input x;
        signal input i;
        signal output o;
        component g[2];
        for (var k = 0; k < 2; k++) {
            g[k] = G(k);
            g[k].x <== x;
        }
        o <-- g[1].out[i];
    }
    component main = Main();
"""
case(f"{G}/runtime/mixed_component_output_index", MIXED_OUT, {"x": "3", "i": "2"}, flags=S3, runtime_error=OOB)
case(f"{G}/correct/mixed_component_output_in_bounds", MIXED_OUT, {"x": "3", "i": "1"}, {"o": 4}, flags=S3)
case(f"{G}/correct/subcomponent_output_in_bounds", SUB_OUT, {"i": "1"}, {"o": 2}, flags=S3)
case(f"{G}/runtime/index_minus_2pow32", READ_VAR, {"i": str(P - 2**32 + 1)}, flags=S3, runtime_error=OOB)
case(f"{G}/runtime/index_sum_wraps_32bits", READ_VAR.replace("a[i]", "a[i + i]"), {"i": str(2**31)}, flags=S3,
     runtime_error=OOB)
case(f"{G}/runtime/size0_dimension_index", """
    pragma circom 2.2.0;
    template Main(n) {
        signal input i;
        signal output o;
        var a[n];
        var s = 0;
        if (i == 7) {
            s = a[i];
        }
        o <-- s;
    }
    component main = Main(0);
""", {"i": "7"}, flags=S3, runtime_error=OOB)

G = "division_by_zero"
case(f"{G}/runtime/mod_in_function", FDIV.replace("OP", "%"), {"a": "3", "b": "0"}, flags=S3, runtime_error=DIVZ)
case(f"{G}/correct/mod_nonzero", DIV.replace("OP", "%"), {"a": "7", "b": "4"}, {"o": 3}, flags=S3)

G = "template_loops"
case(f"{G}/correct/deep_recursion_2000", """
    pragma circom 2.2.0;
    template A(n) {
        signal input in;
        signal output o;
        if (n > 0) {
            component a = A(n - 1);
            a.in <== in;
            o <== a.o + 1;
        } else {
            o <== in;
        }
    }
    component main = A(2000);
""", {"in": "3"}, {"o": 2003}, levels="1", notes="Used to overflow the stack (more than ~300 nested template calls).")
case(f"{G}/compile_error/mutual_growing_parameters", """
    pragma circom 2.2.0;
    template A(n) { component b = B(n + 1); }
    template B(n) { component a = A(n + 1); }
    component main = A(0);
""", error=["error[T3001]", "Too many nested template calls"], levels="0")

G = "size_zero"
case(f"{G}/correct/mixed_with_size0_bus_field", """
    pragma circom 2.2.0;
    bus B {
        signal a[0];
        signal x;
    }
    template T(K) {
        signal input in;
        signal output z[K];
        signal output o;
        input B() b;
        for (var i = 0; i < K; i++) { z[i] <== in; }
        o <== in + b.x;
    }
    template Main() {
        signal input x;
        signal output o[2];
        component t[2];
        B() bb[2];
        for (var k = 0; k < 2; k++) {
            t[k] = T(k);
            t[k].in <== x;
            bb[k].x <== x;
            t[k].b <== bb[k];
            o[k] <== t[k].o;
        }
    }
    component main = Main();
""", {"x": "3"}, {"o": [6, 6]}, flags=S3)

G = "while_inside_if"
case(f"{G}/correct/local_variables_of_unknown_branch", """
    pragma circom 2.2.0;
    template Main() {
        signal input x;
        signal output h;
        signal output k[3];
        if (x != 0) {
            var t = 3;
            var acc = 0;
            for (var i = 0; i < t; i++) {
                acc += i;
                k[i] <-- acc;
            }
            h <-- acc + t;
        } else {
            var u[2] = [4, 5];
            h <-- u[1];
            for (var j = 0; j < 3; j++) {
                k[j] <-- u[0];
            }
        }
    }
    component main = Main();
""", {"x": "1"}, {"h": 6, "k": [0, 1, 3]})
case(f"{G}/compile_error/outer_counter_in_unknown_branch", """
    pragma circom 2.2.0;
    template Main() {
        signal input x;
        signal output h;
        var j = 0;
        if (x != 0) {
            while (j < 2) {
                h <-- j;
                j++;
            }
        }
    }
    component main = Main();
""", error=["error[T3001]", "already assigned"], levels="0",
     notes="j is declared outside the unknown branch: the loop is unknown and h may be assigned several times.")

G = "sugar_lowering"
case(f"{G}/correct/swap_2d_rows", """
    pragma circom 2.2.0;
    template Main() {
        signal input a;
        signal output o[4];
        var m[2][2] = [[a, a + 1], [a + 2, a + 3]];
        m = [m[1], m[0]];
        m[0] = [m[0][1], m[0][0]];
        for (var i = 0; i < 2; i++) {
            for (var j = 0; j < 2; j++) {
                o[2 * i + j] <-- m[i][j];
            }
        }
    }
    component main = Main();
""", {"a": "10"}, {"o": [13, 12, 10, 11]})
case(f"{G}/correct/rotation_in_loop", """
    pragma circom 2.2.0;
    function rot(a, b, c, n) {
        var x[3] = [a, b, c];
        for (var i = 0; i < n; i++) {
            x = [x[2], x[0], x[1]];
        }
        return x[0] * 100 + x[1] * 10 + x[2];
    }
    template Main() {
        signal input n;
        signal output o;
        signal output k;
        o <-- rot(1, 2, 3, n);
        k <-- rot(1, 2, 3, 2);
    }
    component main = Main();
""", {"n": "1"}, {"o": 312, "k": 231})
case(f"{G}/correct/while_condition_with_ternary_and_call", """
    pragma circom 2.2.0;
    function g(x) {
        return x * x;
    }
    function f(n) {
        var i = 0;
        var s = 0;
        while ((i < 2 ? g(i) : g(i) + 1) < n) {
            s += i;
            i++;
        }
        return s * 100 + i;
    }
    template Main() {
        signal input n;
        signal output o;
        o <-- f(n);
    }
    component main = Main();
""", {"n": "10"}, {"o": 303},
     notes="i = 0: 0 < 10, i = 1: 1 < 10, i = 2: 5 < 10, i = 3: 10 < 10 is false: s = 0 + 1 + 2 and i = 3.")
case(f"{G}/correct/for_condition_with_call_and_return", """
    pragma circom 2.2.0;
    function g(x) {
        return x + 1;
    }
    function f(n) {
        for (var i = 0; g(i) < n; i++) {
            if (i == 3) {
                return 100 + i;
            }
        }
        return 7;
    }
    template Main() {
        signal input n;
        signal output o;
        signal output k;
        o <-- f(n);
        k <-- f(3);
    }
    component main = Main();
""", {"n": "10"}, {"o": 103, "k": 7})

print("cases generated in", ROOT)
