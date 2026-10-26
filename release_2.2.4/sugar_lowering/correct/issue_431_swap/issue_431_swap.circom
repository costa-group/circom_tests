pragma circom 2.1.0;

template Main() {
    signal input a;
    signal input b;
    signal output o1;
    signal output o2;
    var x[2] = [a, b];
    x = [x[1], x[0]];
    o1 <== x[0] * a;
    o2 <== x[1] * a;
    log("o1 =", o1, " o2 =", o2);
}

component main = Main();
