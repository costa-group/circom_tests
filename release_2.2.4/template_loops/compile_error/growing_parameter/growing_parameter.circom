pragma circom 2.2.0;
template A(n) {
    signal input in;
    signal output o;
    component a = A(n + 1);
    a.in <== in;
    o <== a.o;
}
component main = A(0);
