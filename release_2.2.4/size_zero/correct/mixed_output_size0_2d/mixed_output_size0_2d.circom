pragma circom 2.2.0;
template G(K) {
    signal input x;
    signal output z[K][3];
    signal output out;
    for (var i = 0; i < K; i++) {
        for (var j = 0; j < 3; j++) {
            z[i][j] <== x + i + j;
        }
    }
    out <== x;
}
template Main() {
    signal input a;
    signal output o[2];
    signal output w;
    component g[2];
    for (var i = 0; i < 2; i++) {
        g[i] = G(2 * i);
        g[i].x <== a;
        o[i] <== g[i].out;
    }
    w <== g[1].z[1][2];
}
component main = Main();
