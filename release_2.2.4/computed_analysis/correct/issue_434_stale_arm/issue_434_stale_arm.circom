pragma circom 2.1.0;

template Main() {
    signal input a;
    signal output h[2];
    var v = 5;
    for (var i = 0; i < 2; i++) {
        h[i] <-- v != 0 ? v : 7;
        v = a;
    }
    log("h[0] =", h[0], " h[1] =", h[1]);
}

component main = Main();
