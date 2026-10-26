template A() { component b = B(); }
template B() { component a = A(); }
component main = A();
