pragma circom 2.2.0;
template T() {
    signal input a;
    signal output b;
    var v = 1 << (1 << 30);
    var w = 1 << (1 << 31);
    b <== a + v + w;
}
component main = T();
