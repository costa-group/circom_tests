pragma circom 2.2.0;
bus B(n) {
    signal x[n];
}
template Main(n) {
    signal input a;
    signal output b;
    b <== a * n;
}
function f(x) { return x; }
component main = Main( Main(4)() );
