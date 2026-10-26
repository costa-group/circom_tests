pragma circom 2.2.0;
template Main() {
    signal input dummy;
    signal output c[6];
    c[0] <-- 1 << 63;
    c[1] <-- 3 << 63;
    c[2] <-- 1 << 64;
    c[3] <-- 1 >> 64;
    c[4] <-- 5 << 18446744069414584320;
    c[5] <-- 5 << 2000000000;
}
component main = Main();
