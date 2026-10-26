pragma circom 2.1.0;

function g(a, b) {
    assert(b != 0);
    return a % b;
}

template Main() {
    signal input a;
    signal input b;
    signal output y;
    if (b != 0) y <-- g(a, b) + 1; else y <-- 7;
    log("y =", y);
}

component main = Main();
