pragma circom 2.2.0;
template G(K) {
    signal input x;
    signal output out[2];
    signal aux[K];
    out[0] <== x;
    out[1] <== x + K;
}
template Main() {
    signal input x;
    signal input i;
    signal output o;
    component g[2];
    for (var k = 0; k < 2; k++) {
        g[k] = G(k);
        g[k].x <== x;
    }
    o <-- g[1].out[i];
}
component main = Main();
