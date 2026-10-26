pragma circom 2.1.0;

function g(x) {
    return x;
}

function f(n) {
    var i = 0;
    var s = 0;
    while (g(i) < n) {
        s += 10;
        i++;
        if (i > 5) {
            return 1000 + s;   // only here to bound the loop
        }
    }
    return s;
}

template Main() {
    signal input n;
    signal output o;
    signal output k;
    o <-- f(n);
    k <-- f(3);
    log("o =", o, " k =", k);
}

component main = Main();
