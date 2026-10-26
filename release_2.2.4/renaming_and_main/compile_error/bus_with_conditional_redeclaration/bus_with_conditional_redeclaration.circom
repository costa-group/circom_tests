pragma circom 2.2.0;
bus B(n) {
    signal a;
    if (n == 0) {
        signal a;
    }
}
template T() {
    signal input x;
    signal output y;
    B(0) b;
    b.a <== x;
    y <== b.a;
}
component main = T();
