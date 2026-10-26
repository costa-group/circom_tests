REGRESSION (3a9efd5, works with v2.2.3). C++: the store of size 0 into the output of a parallel template opens a block that is never
closed (code_producers store_bucket.rs: the '}' is only emitted in the size != 0 branches).
