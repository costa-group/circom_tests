pragma circom 2.2.0;
template Leaf(k) {
    signal input in;
    signal output out;
    out <== in * k;
}
template Node(n) {
    signal input in;
    signal output out;
    component l[n];
    var acc = 0;
    for (var i = 0; i < n; i++) {
        l[i] = Leaf(i + 1);
        l[i].in <== in;
        acc += l[i].out;
    }
    out <== acc;
}
template Main() {
    signal input in;
    signal output out;
    component a = Node(3);
    component b = Node(3);
    a.in <== in;
    b.in <== a.out;
    out <== b.out;
}
component main = Main();
