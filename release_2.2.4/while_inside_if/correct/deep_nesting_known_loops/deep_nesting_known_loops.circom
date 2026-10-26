pragma circom 2.2.0;
template Main() {
    signal input x;
    signal input y;
    signal output h;
    var acc = 0;
    if (x != 0) {
        for (var i = 0; i < 3; i++) {
            if (y != 0) {
                for (var j = 0; j < 3; j++) {
                    while (acc < 4) { acc++; }
                }
            } else {
                for (var k = 0; k < 2; k++) { acc += 2; }
            }
        }
        h <-- acc;
    } else {
        var t = 0;
        while (t < 3) { t++; }
        h <-- t;
    }
}
component main = Main();
