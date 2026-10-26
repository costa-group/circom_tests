pragma circom 2.2.0;
template Main() {
    signal input x[3];
    signal input en;
    signal output out[3];
    for (var i = 0; i < 3; i++) {
        out[i] <-- (i > 0 && en == 1) ? x[i - 1] : 0;
    }
}
component main = Main();
