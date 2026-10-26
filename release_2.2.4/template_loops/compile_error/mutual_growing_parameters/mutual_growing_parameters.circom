pragma circom 2.2.0;
template A(n) { component b = B(n + 1); }
template B(n) { component a = A(n + 1); }
component main = A(0);
