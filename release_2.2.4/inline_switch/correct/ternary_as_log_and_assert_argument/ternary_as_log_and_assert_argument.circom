pragma circom 2.2.0;
template Main() {
    signal input c;
    signal output o;
    log(c != 0 ? 1 : 2);
    log("v", c != 0 ? c : 5);
    assert(c != 0 ? c == 3 : 1);
    o <-- c;
}
component main = Main();
