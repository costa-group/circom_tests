pragma circom 2.2.0;
template T(n) {
    signal input a;
    signal output o;
    if (n == 0) {
        signal t;
        t <== a;
    }
    if (n == 0) {
        signal t;
        t <== a;
    }
    o <== a;
}
component main = T(0);
