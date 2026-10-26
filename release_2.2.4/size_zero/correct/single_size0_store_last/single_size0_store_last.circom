pragma circom 2.2.0;
template G(K) {
    signal input x;
    signal input in[K];
    signal output out;
    out <== x;
    log("run");
}
template Main() {
    signal input a;
    signal output o;
    signal empty[0];
    component c = G(0);
    c.x <== a; c.in <== empty;
    o <== c.out;
}
component main = Main();
