pragma circom 2.2.0;
template Main() {
    signal input x;
    signal output h;
    if (x != 0) {
        for (var i = 0; i < 3; i++) { }
        h <-- 1;
    } else {
        h <-- 2;
    }
    h <-- 3;
}
component main = Main();
