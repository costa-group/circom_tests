pragma circom 2.2.0;
bus B {
    signal a[2];
}
template Main() {
    signal input idx;
    B b;
    b.a[idx] <-- 7;
    signal output y;
    y <== idx;
}
component main = Main();
