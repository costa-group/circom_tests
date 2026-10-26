pragma circom 2.2.0;
function f(n) {
    return n == 0 ? 1 : n * f(n - 1);
}
template Main() {
    signal input x;
    signal output o;
    o <-- f(x);
}
component main = Main();
