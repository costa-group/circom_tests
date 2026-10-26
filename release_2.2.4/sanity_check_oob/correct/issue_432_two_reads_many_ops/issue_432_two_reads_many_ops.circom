pragma circom 2.2.0;
template Main() {
    signal input x;
    signal output o;
    var a[2] = [10, 20];
    var b[2] = [1, 2];
    // (0*1)+0+1 = 1 and 1*1 = 1
    o <-- a[(x - 5) * (x - 4) + (x - 5) + 1] + b[(x - 4) * (x - 4)];
}
component main = Main();
