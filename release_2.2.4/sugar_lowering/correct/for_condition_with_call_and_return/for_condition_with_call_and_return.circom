pragma circom 2.2.0;
function g(x) {
    return x + 1;
}
function f(n) {
    for (var i = 0; g(i) < n; i++) {
        if (i == 3) {
            return 100 + i;
        }
    }
    return 7;
}
template Main() {
    signal input n;
    signal output o;
    signal output k;
    o <-- f(n);
    k <-- f(3);
}
component main = Main();
