pragma circom 2.2.0;
function h(a) {
    assert(a != 0);
    return a;
}
template Main() {
    signal input a;
    signal input b;
    signal output y;
    if (b != 0) y <-- 1; else if (h(a) > 0) y <-- 2; else y <-- 3;
}
component main = Main();
