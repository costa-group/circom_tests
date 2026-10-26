pragma circom 2.2.0;
function g(x) {
    return x;
}
template Main() {
    signal input n;
    signal output o;
    var i = 0;
    var s = 0;
    while (g(i) < n && i < 6) {
        s += 10;
        i++;
    }
    o <-- s;
}
component main = Main();
