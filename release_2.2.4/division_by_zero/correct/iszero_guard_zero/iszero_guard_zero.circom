pragma circom 2.2.0;
template Main() {
    signal input a;
    signal output out;
    signal inv;
    inv <-- a != 0 ? 1 / a : 0;
    out <== -a * inv + 1;
    a * out === 0;
}
component main = Main();
