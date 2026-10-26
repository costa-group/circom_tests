Bug found by this test (fixed): % is not checked at --sanity_check 3 (only / and \ are): wasm traps with
"RuntimeError: divide by zero" and C++ crashes inside GMP (SIGFPE).
