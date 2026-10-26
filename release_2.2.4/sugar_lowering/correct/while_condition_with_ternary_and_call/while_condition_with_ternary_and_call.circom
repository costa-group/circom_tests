pragma circom 2.2.0;
function g(x) {
    return x * x;
}
function f(n) {
    var i = 0;
    var s = 0;
    while ((i < 2 ? g(i) : g(i) + 1) < n) {
        s += i;
        i++;
    }
    return s * 100 + i;
}
template Main() {
    signal input n;
    signal output o;
    o <-- f(n);
}
component main = Main();
