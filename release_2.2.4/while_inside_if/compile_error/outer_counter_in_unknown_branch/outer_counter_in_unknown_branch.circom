pragma circom 2.2.0;
template Main() {
    signal input x;
    signal output h;
    var j = 0;
    if (x != 0) {
        while (j < 2) {
            h <-- j;
            j++;
        }
    }
}
component main = Main();
