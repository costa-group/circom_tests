pragma circom 2.2.0;
template Main() {
    signal input a;
    signal input b;
    signal output o;
    o <-- a \ b;
}
component main = Main();
