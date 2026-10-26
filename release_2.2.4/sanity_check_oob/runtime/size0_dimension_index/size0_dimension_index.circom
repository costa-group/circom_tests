pragma circom 2.2.0;
template Main(n) {
    signal input i;
    signal output o;
    var a[n];
    var s = 0;
    if (i == 7) {
        s = a[i];
    }
    o <-- s;
}
component main = Main(0);
