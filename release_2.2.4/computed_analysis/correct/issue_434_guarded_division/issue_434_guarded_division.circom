pragma circom 2.1.0;

template Main() {
    signal input a;
    signal h[2];
    signal s[2];
    signal t[2];
    var v = 5;
    for (var i = 0; i < 2; i++) {
        h[i] <-- (v - 3) != 0 ? 1 / (v - 3) : 0;
        s[i] <== 1 - (v - 3) * h[i];
        (v - 3) * s[i] === 0;
        t[i] <== a * a;
        v = t[i];
    }
}

component main = Main();
