pragma circom 2.2.0;
template Main() {
    signal input x;
    signal output o;
    var a[4] = [1, 2, 3, 4];
    o <-- a[((x * x - 16) \ 3) + (x - 5)];   // 9 \ 3 + 0 = 3
}
component main = Main();
