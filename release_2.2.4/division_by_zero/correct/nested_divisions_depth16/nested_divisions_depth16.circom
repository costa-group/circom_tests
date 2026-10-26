pragma circom 2.2.0;
template Main() {
    signal input x[17];
    signal output o;
    o <-- x[16] / (x[15] / (x[14] / (x[13] / (x[12] / (x[11] / (x[10] / (x[9] / (x[8] / (x[7] / (x[6] / (x[5] / (x[4] / (x[3] / (x[2] / (x[1] / (x[0]))))))))))))))));
}
component main = Main();
