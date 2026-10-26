pragma circom 2.2.0;
template Main() {
    signal input x;
    signal output o;
    var a[3] = [1, 2, 3];
    var acc = 0;
    for (var k = 0; k < 3; k++) {
        acc += a[(x - 5) + k];
    }
    o <-- acc;
}
component main = Main();
