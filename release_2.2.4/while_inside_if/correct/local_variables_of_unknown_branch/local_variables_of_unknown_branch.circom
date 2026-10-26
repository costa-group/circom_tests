pragma circom 2.2.0;
template Main() {
    signal input x;
    signal output h;
    signal output k[3];
    if (x != 0) {
        var t = 3;
        var acc = 0;
        for (var i = 0; i < t; i++) {
            acc += i;
            k[i] <-- acc;
        }
        h <-- acc + t;
    } else {
        var u[2] = [4, 5];
        h <-- u[1];
        for (var j = 0; j < 3; j++) {
            k[j] <-- u[0];
        }
    }
}
component main = Main();
