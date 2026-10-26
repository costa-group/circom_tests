pragma circom 2.1.0;
function sw(a, b) {
    var x[2] = [a, b];
    x = [x[1], x[0]];
    return x[0] * 10 + x[1];
}
template Main() {
    signal input a;
    signal input b;
    signal output h;
    signal output k;
    h <-- sw(a, b);
    k <-- sw(1, 2);
}
component main = Main();
