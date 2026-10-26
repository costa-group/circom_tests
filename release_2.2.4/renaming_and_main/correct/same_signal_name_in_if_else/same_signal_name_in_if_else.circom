pragma circom 2.2.0;
template T(n) {
    signal input a;
    signal output o;
    if (n == 0) {
        signal t;
        t <== a;
        o <== t;
    } else {
        signal t;
        t <== a * a;
        o <== t;
    }
}
component main = T(1);
