pragma circom 2.2.0;
template T() {
    signal output out[2];
    out[0] <== 1;
    out[1] <== 2;
}
template Main() {
    signal input i;
    signal output o;
    component t = T();
    o <-- t.out[i];
}
component main = Main();
