pragma circom 2.2.0;
template Main() {
    signal input a;
    signal input b;
    signal output o;
    if (b != 0) {
        o <-- a / b;
    } else {
        o <-- 0;
    }
}
component main = Main();
