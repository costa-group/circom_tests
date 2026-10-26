pragma circom 2.2.0;

function g(a, b) {
    assert(b != 0);
    return a % b;
}

template Main() {
    signal input a;
    signal input b;
    signal output y;
    if (b != 0) y <-- (a > 1 ? g(a, b) : 1) + 1; else y <-- 3;
}
component main = Main();
