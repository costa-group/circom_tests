pragma circom 2.2.0;
template Main() {
    signal input x;
    signal output h;
    for (var i = 0; i < 2; i++) {
        if (x != 0) {
            h <-- 1;
        } else {
            h <-- 2;
        }
    }
}
component main = Main();
