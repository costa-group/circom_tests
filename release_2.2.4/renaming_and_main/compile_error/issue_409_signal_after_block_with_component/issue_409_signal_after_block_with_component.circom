pragma circom 2.2.0;
template Sub() {
    signal input in;
    signal output out;
    out <== in;
}
template Demo() {
    signal input x;
    signal output y;
    if (1 == 1) {
        signal foo <== x;
        component s = Sub();
        s.in <== foo;
        y <== s.out;
    }
    signal foo <== 2;
}
component main = Demo();
