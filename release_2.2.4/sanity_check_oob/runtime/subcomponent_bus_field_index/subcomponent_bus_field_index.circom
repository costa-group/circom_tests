pragma circom 2.2.0;
bus B {
    signal a[2];
}
template T() {
    output B() ob;
    ob.a[0] <== 1;
    ob.a[1] <== 2;
}
template Main() {
    signal input idx;
    signal output y;
    component t = T();
    y <-- t.ob.a[idx];
}
component main = Main();
