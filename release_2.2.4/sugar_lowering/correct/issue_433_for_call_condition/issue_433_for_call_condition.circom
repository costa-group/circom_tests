pragma circom 2.1.0;
function g(x) {
    return x;
}
function f(n) {
    var s = 0;
    for (var i = 0; g(i) < n; i++) {
        s += 10;
        if (i > 4) {
            return 1000 + s;
        }
    }
    return s;
}
template Main() {
    signal input n;
    signal output o;
    o <-- f(n);
}
component main = Main();
