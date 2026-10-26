pragma circom 2.2.0;
template A(n) {
    signal input in;
    signal output out;
    component a = A(n);
    a.in <== in;
    out <== a.out;
}
component main = A(3);
