pragma circom 2.2.0;
template A() {
    signal input in;
    signal output out;
    out <== B()(in);
}
template B() {
    signal input in;
    signal output out;
    out <== A()(in);
}
component main = A();
