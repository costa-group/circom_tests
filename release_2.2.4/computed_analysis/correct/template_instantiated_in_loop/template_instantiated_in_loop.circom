pragma circom 2.2.0;
template T(n) {
    signal input e[n * 3];
    signal output out;
    var s = 0;
    for (var i = 0; i < n * 3; i++) {
        s += e[i];
    }
    out <== s;
}
template M() {
    signal input a;
    signal output o[2];
    component c[2];
    for (var k = 0; k < 2; k++) {
        c[k] = T(2);
        for (var i = 0; i < 6; i++) {
            c[k].e[i] <== a;
        }
        o[k] <== c[k].out;
    }
}
component main = M();
