pragma circom 2.2.0;
template parallel P(n) {
    signal input a[n];
    signal input b;
    signal output z[n];
    signal output o;
    z <== a;
    o <== b + 1;
}
template Main() {
    signal input b;
    signal output o;
    component p = P(0);
    p.b <== b;
    o <== p.o;
}
component main = Main();
