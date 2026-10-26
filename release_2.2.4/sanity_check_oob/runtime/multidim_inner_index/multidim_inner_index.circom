pragma circom 2.2.0;
template Main() {
    signal input i;
    signal input j;
    signal output o;
    var a[2][3] = [[1, 2, 3], [4, 5, 6]];
    o <-- a[i][j];
}
component main = Main();
