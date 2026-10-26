pragma circom 2.99999999999999999999.0;
template T() { signal input a; signal output b; b <== a; }
component main = T();
