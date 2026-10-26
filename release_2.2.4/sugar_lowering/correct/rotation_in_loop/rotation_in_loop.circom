pragma circom 2.2.0;
function rot(a, b, c, n) {
    var x[3] = [a, b, c];
    for (var i = 0; i < n; i++) {
        x = [x[2], x[0], x[1]];
    }
    return x[0] * 100 + x[1] * 10 + x[2];
}
template Main() {
    signal input n;
    signal output o;
    signal output k;
    o <-- rot(1, 2, 3, n);
    k <-- rot(1, 2, 3, 2);
}
component main = Main();
