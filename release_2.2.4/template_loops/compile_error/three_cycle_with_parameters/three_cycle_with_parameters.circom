pragma circom 2.2.0;
template A(n) { component b = B(n + 1); }
template B(n) { component c = C(n - 1); }
template C(n) { component a = A(n); }
component main = A(1);
