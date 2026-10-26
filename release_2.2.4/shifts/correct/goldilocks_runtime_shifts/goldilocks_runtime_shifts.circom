pragma circom 2.2.0;
template Main() {
    signal input x[6];
    signal input s[6];
    signal output c[6];
    c[0] <-- x[0] << s[0];
    c[1] <-- x[1] << s[1];
    c[2] <-- x[2] << s[2];
    c[3] <-- x[3] >> s[3];
    c[4] <-- x[4] << s[4];
    c[5] <-- x[5] << s[5];
}
component main = Main();
