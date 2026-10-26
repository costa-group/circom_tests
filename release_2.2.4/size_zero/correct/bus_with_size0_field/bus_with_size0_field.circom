pragma circom 2.2.0;
bus B {
    signal a[0];
    signal x;
}
template Main() {
    signal input in;
    signal output o;
    B t;
    t.x <== in;
    o <== t.x;
}
component main = Main();
