pragma circom 2.2.0;
function s(v) {
    return v[0] + v[1];
}
template Main() {
    signal input a;
    signal input b;
    signal input c;
    signal output y;
    y <-- c != 0 ? s([a, b]) : 0;
}
component main = Main();
