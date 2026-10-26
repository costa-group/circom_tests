pragma circom 2.2.0;
template A(n) {
    signal input in;
    signal output out;
    if (n > 2) {
        component a = A(n - 1);
        a.in <== in;
        out <== a.out;
    } else {
        component a = A(n);
        a.in <== in;
        out <== a.out;
    }
}
component main = A(4);
