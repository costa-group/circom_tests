pragma circom 2.2.0;
template Main() {
    signal input i;
    signal output o;
    var a[2] = [7, 8];
    o <-- a[4 * i];
}
component main = Main();
