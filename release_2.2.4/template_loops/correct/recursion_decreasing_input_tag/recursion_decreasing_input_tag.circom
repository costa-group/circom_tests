pragma circom 2.2.0;
template A() {
    signal input {maxv} in;
    signal output o;
    if (in.maxv > 0) {
        signal {maxv} t;
        t.maxv = in.maxv - 1;
        t <== in;
        component a = A();
        a.in <== t;
        o <== a.o + 1;
    } else {
        o <== in;
    }
}
template Main() {
    signal input x;
    signal output o;
    signal {maxv} t;
    t.maxv = 3;
    t <== x;
    component a = A();
    a.in <== t;
    o <== a.o;
}
component main = Main();
