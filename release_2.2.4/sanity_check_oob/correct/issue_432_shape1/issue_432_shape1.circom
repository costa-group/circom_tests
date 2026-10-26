pragma circom 2.2.0;

template Main() {
    signal input x;
    signal output o;
    var a[2] = [7, 8];
    o <-- a[(x - 5) + (x - 4)];
    log("o =", o);
}

component main = Main();
