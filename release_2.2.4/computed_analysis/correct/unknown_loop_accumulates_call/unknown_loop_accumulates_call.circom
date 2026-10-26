pragma circom 2.2.0;
function g(x) {
    return x;
}
template Main() {
    signal input n;
    signal output o;
    var i = 0;
    var s = 0;
    while (i < n) {
        s = s + g(i);
        i++;
    }
    o <-- s;
}
component main = Main();
