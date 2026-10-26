pragma circom 2.2.0;
function g(y) {
    return y + 1;
}
template Main() {
    signal input x;
    signal output o;
    var r[3] = [0, 0, 0];
    r[(x - 4) + (x - 4)] = g(x);   // r[2] = 6
    o <-- r[2];
}
component main = Main();
