pragma circom 2.2.0;
template Main() {
    signal input x;
    signal output o;
    var a[3] = [0, 0, 0];
    a[(x - 3) % (x - 1)] = x;   // 1 % 3 = 1
    o <-- a[1];
}
component main = Main();
