pragma circom 2.2.0;
bus B {
    signal a;
    signal a;
}
template T() {
    signal input x;
    signal output y;
    B b;
    b.a <== x;
    y <== b.a;
}
component main = T();
