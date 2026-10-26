pragma circom 2.2.0;

function f(p) {
    var a[1] = [0];
    var v = a[0 % (5 + 4)];
    return p;
}

template Main() {
    signal input x;
    signal output o;
    o <-- f(x);
    log("o =", o);
}

component main = Main();
