pragma circom 2.2.0;
bus S2() {
    signal {a} aux[1];
}
bus S() {
    S2 {b} aux[1];
}
template A() {
    input S() {c} inter[1];
    signal output o;
    var n = 0;
    for (var i = 0; i < inter.c; i++) {
        n += 1;
    }
    o <== inter[0].aux[0].aux[0] * n;
}
template B() {
    signal input x;
    signal output y;
    component a[1];
    a[0] = A();
    signal {a} anda;
    anda.a = 5;
    anda <== x;
    S2() {b} p2;
    p2.b = 4;
    S() {c} p;
    p.c = 3;
    p2.aux[0] <== anda;
    p.aux[0] <== p2;
    a[0].inter[0] <== p;
    y <== a[0].o;
}
component main = B();
