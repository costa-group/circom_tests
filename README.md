# circom_tests

Regression tests for the circom compiler. Every test case is a directory `D` that contains
`D/<basename(D)>.circom` plus at least one expectation file. Cases are grouped in arbitrary
category/subcategory directories.

## Running

```sh
python3 run_tests.py --circom /path/to/circom                       # whole suite
python3 run_tests.py --circom ../target/release/circom --only release_2.2.4 --jobs 12
python3 run_tests.py --circom ... --only tags_2.2 --levels 0 --no-cpp --report report.md
```

Requirements: python3 (standard library only), node (wasm witness), and g++, make, nasm, gmp and
nlohmann-json (C++ witness, skip with `--no-cpp`).

For each case and each level of `--levels` (default `0,1,2`, overridable per case) the runner
compiles with `--O<n>` and checks the expectations below. The object files shared by every
generated C++ project are cached in the work directory, so only `<case>.cpp` is compiled per case.

Main options: `--only <dirs>`, `--levels 0,2`, `--no-cpp`, `--jobs N`, `--keep` (keep build
outputs in `--workdir`), `--report out.md`, `-v` (full logs), `--generate [--force]` (write golden
`witness/result_O<n>.wtns` and `r1cs/<case>_O<n>.{r1cs,sym}` from the current compiler; only do this
after checking the values with `expected_outputs.json`).

## Case format

| File | Meaning |
|---|---|
| `witness/input.json` | Correct case. The witness is computed with wasm and C++; both must succeed, be equal, print the same logs and satisfy the R1CS. |
| `witness/expected_outputs.json` | Expected values of the outputs of `main`, e.g. `{"o": 8, "h": [5, 2]}` (negative numbers are taken mod p). |
| `witness/result_O<n>.wtns`, `r1cs/<case>_O<n>.r1cs` | Golden snapshots. A mismatch is reported as `DIFF`, not `FAIL`. |
| `expected_log.txt` | Exact lines printed by `log()` during witness generation. |
| `error.txt` | Golden stderr of a compilation that must fail. Compared after normalizing colors, paths and the pragma version; if only the text differs but the error codes match, the result is `DIFF`. If it records a successful compilation ("Everything went okay"), the case only checks that the circuit compiles. |
| `expected_error.txt` | Substrings (one per line) that the stderr of a compilation that must fail has to contain. |
| `expected_runtime_error.txt` | The circuit compiles but witness generation must fail. One substring per line; prefix `wasm:` or `cpp:` to restrict a line to one backend. Needs `witness/input.json`. |
| `flags.txt` | Extra compiler flags, e.g. `--sanity_check 3` or `--prime goldilocks`. |
| `levels.txt` | Simplification levels for this case, e.g. `0` for compile-error cases. |
| `known_bug.txt` | Known open bug: a failure is reported as `XFAIL`, a pass as `XPASS`. |
| `NOTES.md` | Free-form notes about the case. |

A compiler panic or stack overflow is always a `FAIL`.

## Statuses

`PASS`, `FAIL` (semantic failure), `DIFF` (only a golden snapshot differs), `XFAIL`, `XPASS`.
The exit code is 1 iff some case is `FAIL`.

## Other scripts

`check_witness_cvm.sh` runs the CVM pipeline (circom `--cvm` + `cvm-compile`) against the golden
witnesses; `tags_2.2/fails/generate_fails.sh` produces `error.txt` files.
