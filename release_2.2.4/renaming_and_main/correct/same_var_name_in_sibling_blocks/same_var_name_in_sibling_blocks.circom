pragma circom 2.2.0;
template T() {
    signal input a;
    signal output o;
    var acc = 0;
    {
        var t = 2;
        acc += t;
    }
    {
        var t = 3;
        acc += t;
    }
    o <== a * acc;
}
component main = T();
