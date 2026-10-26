pragma circom 2.2.0;

function g(a, b) {
    assert(b != 0);
    return a % b;
}

template Main() {
    signal input a;
    signal input b;
    signal output y;
    var acc = 0;
    for (var i = 0; i < 3; i++) {
        acc += b != 0 ? g(a + i, b) : 7;
    }
    y <-- acc;
}
component main = Main();
