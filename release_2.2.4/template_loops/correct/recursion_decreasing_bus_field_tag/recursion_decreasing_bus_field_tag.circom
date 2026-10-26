pragma circom 2.2.0;
bus B {
    signal {maxv} v;
}
template A() {
    input B() in;
    signal output o;
    if (in.v.maxv > 0) {
        B() t;
        t.v.maxv = in.v.maxv - 1;
        t.v <== in.v;
        component a = A();
        a.in <== t;
        o <== a.o + 1;
    } else {
        o <== in.v;
    }
}
template Main() {
    signal input x;
    signal output o;
    B() t;
    t.v.maxv = 3;
    t.v <== x;
    component a = A();
    a.in <== t;
    o <== a.o;
}
component main = Main();
