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
    signal input b;
    signal output o[3];
    component g[3];
    for (var i = 0; i < 3; i++) {
        g[i] = G(i);
        g[i].x <== a;
        for (var j = 0; j < i; j++) {
            g[i].in[j] <== b;
        }
        o[i] <== g[i].out;
    }
}
component main = Main();
