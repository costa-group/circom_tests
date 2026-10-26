pragma circom 2.2.0;
bus In {
    signal a[2];
}
bus Out {
    In x[3];
}
template Main() {
    signal input i;
    signal input j;
    Out o;
    o.x[i].a[j] <-- 1;
    signal output y;
    y <== i + j;
}
component main = Main();
