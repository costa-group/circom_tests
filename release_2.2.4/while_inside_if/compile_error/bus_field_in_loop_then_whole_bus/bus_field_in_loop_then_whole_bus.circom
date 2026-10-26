pragma circom 2.2.0;
bus P {
    signal f[2];
}
template Main() {
    signal input a;
    signal output o;
    P b;
    P other;
    other.f[0] <== a;
    other.f[1] <== a;
    for (var i = 0; i < 2; i++) {
        b.f[i] <== a;
    }
    b <== other;
    o <== b.f[0];
}
component main = Main();
