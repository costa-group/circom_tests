pragma circom 2.2.0;
function g(a, b) { assert(b != 0); return a % b; }
function f(a, b) {
    if (a > 5) return b > 0 ? (a > 7 ? g(a, b) : 1) : 2;
    else return a == 0 ? 3 : (b == 0 ? 4 : g(b, a));
}
function arr(c, a, b) {
    var v[2] = c != 0 ? [a, b] : [b, a];
    return v[0] * 10 + v[1];
}
template Main() {
    signal input a;
    signal input b;
    signal input c;
    signal output o[6];
    o[0] <-- a > 2 ? (b > 2 ? (c > 2 ? 1 : 2) : 3) : 4;
    o[1] <-- f(a, b);
    o[2] <-- arr(c, a, b);
    var t = c != 0 ? (b != 0 ? g(a, b) : 7) : 9;
    o[3] <-- t;
    log("t", c != 0 ? (b != 0 ? g(a, b) : 7) : 9);
    assert(c != 0 ? t == 7 || b != 0 : t == 9);
    o[4] <-- c != 0 ? g(a, (b != 0 ? b : 1)) : 0;
    var acc = 0;
    for (var i = 0; i < 3; i++) {
        if (b != 0) acc += i > 0 ? g(a + i, b) : 100; else acc += i;
    }
    o[5] <-- acc;
}
component main = Main();
