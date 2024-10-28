#!/bin/bash
line=$1
auxc="_cpp" 
auxw="_js" 
aux0="_O0"
aux1="_O1"
aux2="_O2"

/home/clara/circom/circom_lucas/target/release/circom $line.circom --sym --r1cs --c --wasm --inputs --O0 &> error1.txt

sed -e "s/\x1B[^m]*m//g" error1.txt > error.txt

rm error1.txt
