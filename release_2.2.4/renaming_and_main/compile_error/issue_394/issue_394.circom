template C(n) {
  signal input in;
  signal output out;

  if (n == 0) {
    signal input in;
    signal input in2;
    signal output out;
    out <== in + in2;
  } else {
    signal input in;
    signal input in2;
    out <== in * in2;
  }
}

component main {public [in,in2]} = C(0);
