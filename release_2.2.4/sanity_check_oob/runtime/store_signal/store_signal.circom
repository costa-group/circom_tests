pragma circom 2.2.0;
template Main() {
    signal input idx;
    signal a[2];
    a[idx] <-- 7;
    signal output y;
    y <== idx;
}
component main = Main();
