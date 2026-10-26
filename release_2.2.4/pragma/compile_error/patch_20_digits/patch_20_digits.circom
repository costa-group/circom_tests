pragma circom 2.2.99999999999999999999;
template T() { signal input a; signal output b; b <== a; }
component main = T();
