pragma circom 2.2.0;
template Main() {
    signal input x[16];
    signal input s[16];
    signal output c[16];
    c[0] <-- x[0] << s[0];
    c[1] <-- x[1] >> s[1];
    c[2] <-- x[2] << s[2];
    c[3] <-- x[3] << s[3];
    c[4] <-- x[4] << s[4];
    c[5] <-- x[5] << s[5];
    c[6] <-- x[6] >> s[6];
    c[7] <-- x[7] << s[7];
    c[8] <-- x[8] >> s[8];
    c[9] <-- x[9] >> s[9];
    c[10] <-- x[10] << s[10];
    c[11] <-- x[11] >> s[11];
    c[12] <-- x[12] >> s[12];
    c[13] <-- x[13] << s[13];
    c[14] <-- x[14] << s[14];
    c[15] <-- x[15] << s[15];
}
component main = Main();
