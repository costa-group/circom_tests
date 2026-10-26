pragma circom 2.2.0;
template Main() {
    signal input x;
    signal output h;
    var w = 0;
    if (x != 0) {
        if (x != 6) { } else { while (w < 1) { w++; } }
        h <-- 1;
    } else {
        h <-- 2;
    }
}
component main = Main();
