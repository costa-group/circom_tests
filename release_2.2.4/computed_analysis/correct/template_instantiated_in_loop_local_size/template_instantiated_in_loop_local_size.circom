pragma circom 2.2.0;
template T(n) {
    signal input in;
    signal output out;
    var m = n + 1;
    signal acc[m];
    acc[0] <== in;
    for (var i = 1; i < m; i++) {
        acc[i] <== acc[i - 1] * in;
    }
    out <== acc[m - 1];
}
template M() {
    signal input a;
    signal output o[3];
    component c[3];
    var i = 0;
    while (i < 3) {
        c[i] = T(i);
        c[i].in <== a;
        o[i] <== c[i].out;
        i++;
    }
}
component main = M();
