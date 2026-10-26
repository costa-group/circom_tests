pragma circom 2.1.0;
template Main() {
    signal input a;
    signal output h[2];
    var v = 5;
    for (var i = 0; i < 2; i++) {
        var r = 7;
        if (v != 0) { r = v; }
        h[i] <-- r;
        v = a;
    }
}
component main = Main();
