pragma circom 2.2.0;
function g(x) {
    assert(x != 0);
    return x;
}
template Main() {
    signal input s;
    signal output h;
    h <-- s != 0 ? g(0) : 1;
}
component main = Main();
