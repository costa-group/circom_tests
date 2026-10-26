pragma circom 2.2.0;
function g(x) {
    return x + 1;
}
function f(n) {
    var s = 0;
    while (s < n) s = s + g(s);
    return s;
}
template Main() {
    signal input n;
    signal output o;
    o <-- f(n);
}
component main = Main();
