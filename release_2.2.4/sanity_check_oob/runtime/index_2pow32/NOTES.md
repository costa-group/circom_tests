Bug found by this test (fixed): Fr_toInt keeps the low 32 bits in wasm, so i = 2^32 reads a[0] without error.
In C++ (bn128) Fr_toInt aborts without the out-of-bounds message.
