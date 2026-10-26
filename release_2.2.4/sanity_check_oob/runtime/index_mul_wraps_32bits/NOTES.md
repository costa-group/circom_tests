Bug found by this test (fixed): Index arithmetic is done in 32 bits (AddAddress/MulAddress): 4 * 2^30 wraps to 0 and passes the check.
