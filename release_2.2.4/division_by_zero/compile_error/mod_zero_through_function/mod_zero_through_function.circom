pragma circom 2.1.0;
function f(x) {
    return 7 % x;
}
template T() {
    signal output o;
    var v = f(0);
    o <== v;
}
component main = T();
