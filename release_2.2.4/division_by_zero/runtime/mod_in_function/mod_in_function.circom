pragma circom 2.2.0;
function g(x, y) {
    var r = x % y;
    return r;
}
template Main() {
    signal input a;
    signal input b;
    signal output o;
    o <-- g(a, b);
}
component main = Main();
