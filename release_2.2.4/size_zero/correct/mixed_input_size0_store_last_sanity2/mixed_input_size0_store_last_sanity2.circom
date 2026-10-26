pragma circom 2.2.0;
template G(K) {
    signal input x;
    signal input in[K];
    signal output out;
    var s = 0;
    for (var i = 0; i < K; i++) {
        s += in[i];
    }
    out <== x + s;
    log("G", K);
}
template Main() {
    signal input a;
    signal input e1[1];
    signal output o[2];
    signal e0[0];
    component g[2];
    g[0] = G(0);
    g[1] = G(1);
    g[0].x <== a; g[1].x <== a; g[0].in <== e0; g[1].in <== e1;
    o[0] <== g[0].out;
    o[1] <== g[1].out;
}
component main = Main();
