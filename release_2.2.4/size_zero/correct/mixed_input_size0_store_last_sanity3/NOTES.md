Bug found by this test (fixed): C++ runs g[0] = G(0) twice when its size-0 input is stored last (wasm runs it once):
the store gets StatusInput Last/Unknown although it does not decrement the counter.
Fails with v2.2.3 too (there it panics, #436).
