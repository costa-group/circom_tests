pragma circom 2.2.0;

function g(a, b) {
    assert(b != 0);
    return a % b;
}

function f(a, b) {
    return a > 0 ? (b > 0 ? g(a, b) : 7) : 9;
}
template Main() {
    signal input x;
    signal input z;
    signal output o;
    o <-- f(x, z);
}
component main = Main();
