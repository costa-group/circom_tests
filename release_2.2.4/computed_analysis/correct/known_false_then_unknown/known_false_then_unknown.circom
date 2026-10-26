pragma circom 2.2.0;
template Main() {
    signal input a;
    signal output h[3];
    var v = 5;
    for (var i = 0; i < 3; i++) {
        h[i] <-- v != 0 ? v : 7;
        if (i == 0) { v = 0; } else { v = a; }
    }
}
component main = Main();
