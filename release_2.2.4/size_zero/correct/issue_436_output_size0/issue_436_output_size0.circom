pragma circom 2.2.0;

template G(K) {
    signal input x;
    signal output out;
    signal output z[0];
    out <== x;
}

template Main() {
    signal input a;
    signal output o[2];
    component g[2];
    for (var i = 0; i < 2; i++) {
        g[i] = G(i);
        g[i].x <== a;
        o[i] <== g[i].out;
    }
}

component main = Main();
