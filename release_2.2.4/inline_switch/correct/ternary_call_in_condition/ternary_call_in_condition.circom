pragma circom 2.2.0;
function g2(x) {
    assert(x != 0);
    return x - 1;
}
template Main() {
    signal input a;
    signal output y;
    y <-- (a != 0 ? g2(a) : 0) != 0 ? 1 : 2;
}
component main = Main();
