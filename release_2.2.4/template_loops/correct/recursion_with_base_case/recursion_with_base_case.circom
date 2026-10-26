pragma circom 2.2.0;
template A(n) {
    signal input in;
    signal output o;
    if (n > 0) {
        component a = A(n - 1);
        a.in <== in;
        o <== a.o + 1;
    } else {
        o <== in;
    }
}
component main = A(5);
