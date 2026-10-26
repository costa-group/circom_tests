pragma circom 2.2.0;
template Sub() {
    signal input in;
    signal output out;
    out <== in;
}
template T() {
    signal input a;
    signal output o;
    {
        component c = Sub();
        c.in <== a;
    }
    {
        component c = Sub();
        c.in <== a;
        o <== c.out;
    }
}
component main = T();
