pragma circom 2.2.0;
bus B {
    signal a[2];
}
template Main() {
    signal input i;
    signal input j;
    signal output y;
    B b[2];
    for (var k = 0; k < 2; k++) {
        for (var m = 0; m < 2; m++) {
            b[k].a[m] <== 10 * k + m;
        }
    }
    y <-- b[i].a[j];
}
component main = Main();
