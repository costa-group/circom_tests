pragma circom 2.2.0;
template T() {
    signal input a;
    signal output x;
    x <== a;
    {
        var x = 1;
    }
}
component main = T();
