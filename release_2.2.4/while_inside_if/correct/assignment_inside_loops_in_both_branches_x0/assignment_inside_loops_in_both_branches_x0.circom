pragma circom 2.2.0;
template Main() {
    signal input x;
    signal output h;
    if (x != 0) {
        for (var i = 0; i < 1; i++) { h <-- 1; }
    } else {
        for (var j = 0; j < 1; j++) { h <-- 2; }
    }
}
component main = Main();
