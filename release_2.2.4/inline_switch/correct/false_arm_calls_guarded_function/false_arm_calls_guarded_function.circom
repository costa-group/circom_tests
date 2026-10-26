pragma circom 2.2.0;

function g(a, b) {
    assert(b != 0);
    return a % b;
}

template Main() {
    signal input a;
    signal input b;
    signal output y;
    y <-- b == 0 ? 7 : g(a, b);
}
component main = Main();
