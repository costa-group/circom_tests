pragma circom 2.2.0;
template Main() {
    signal input a;
    signal output o[4];
    var m[2][2] = [[a, a + 1], [a + 2, a + 3]];
    m = [m[1], m[0]];
    m[0] = [m[0][1], m[0][0]];
    for (var i = 0; i < 2; i++) {
        for (var j = 0; j < 2; j++) {
            o[2 * i + j] <-- m[i][j];
        }
    }
}
component main = Main();
