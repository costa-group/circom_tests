pragma circom 2.2.0;
function f(i) {
    var a[3] = [0, 0, 0];
    a[i] = 1;
    return a[0] + a[1] + a[2];
}
template Main() {
    signal input i;
    signal output o;
    o <-- f(i);
}
component main = Main();
