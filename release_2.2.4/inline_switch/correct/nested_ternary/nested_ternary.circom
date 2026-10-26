pragma circom 2.2.0;
template Main() {
    signal input a;
    signal input b;
    signal output y;
    y <-- a > 2 ? (b > 2 ? 1 : 2) : 3;
}
component main = Main();
