pragma circom 2.2.0;
template Main() {
    signal input a;
    signal input n;
    signal output o;
    var v = 3;
    var acc = 0;
    for (var i = 0; i < 2; i++) {
        var j = 0;
        while (j < n) {
            acc = acc + (j == 0 ? v : 2 * v);
            j++;
        }
        v = a;
    }
    o <-- acc;
}
component main = Main();
