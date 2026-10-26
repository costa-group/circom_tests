pragma circom 2.2.0;
bus B {
    signal a[0];
    signal x;
}
template T(K) {
    signal input in;
    signal output z[K];
    signal output o;
    input B() b;
    for (var i = 0; i < K; i++) { z[i] <== in; }
    o <== in + b.x;
}
template Main() {
    signal input x;
    signal output o[2];
    component t[2];
    B() bb[2];
    for (var k = 0; k < 2; k++) {
        t[k] = T(k);
        t[k].in <== x;
        bb[k].x <== x;
        t[k].b <== bb[k];
        o[k] <== t[k].o;
    }
}
component main = Main();
