pragma circom 2.2.0;
template Main() {
    signal input x;
    signal output o;
    var b[2] = [7, 8];
    var a[2] = [10, 20];
    o <-- a[b[(x - 5) + (x - 4)] - 7];   // a[8 - 7] = 20
}
component main = Main();
