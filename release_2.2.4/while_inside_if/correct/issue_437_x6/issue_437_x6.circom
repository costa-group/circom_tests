pragma circom 2.2.0;

template Main() {
    signal input x;
    signal output h;
    if (x != 0) {
        if (x != 6) { } else { for (var w = 0; w < 2; w++) { } }
        h <-- 1;
    } else {
        h <-- 2;
    }
}

component main = Main();
