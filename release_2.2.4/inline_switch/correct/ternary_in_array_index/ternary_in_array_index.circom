pragma circom 2.2.0;
template Main() {
    signal input b;
    signal output o;
    var arr[2] = [10, 20];
    o <-- arr[b != 0 ? 1 : 0];
}
component main = Main();
