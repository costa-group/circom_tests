#!/bin/bash
line=$1
auxc="_cpp" 
auxw="_js" 
aux0="_O0"
aux1="_O1"
aux2="_O2"

mkdir witness
mkdir r1cs

/home/clara/circom/circom_lucas/target/release/circom $line.circom --sym --r1cs --c --wasm --inputs --O0
python3 /home/clara/circom/testing/generate_random_inputs.py log_input_signals.txt witness/input.json

cp $line$auxc/$line.cpp $line.cpp
cp $line$auxw/$line.wasm $line.wasm

mv $line.r1cs r1cs/$line$aux0.r1cs
mv $line.sym r1cs/$line$aux0.sym

cd $line$auxc
make
./$line ../witness/input.json ../witness/result$aux0.wtns
cd ..

/home/clara/circom/circom_lucas/target/release/circom $line.circom --sym --r1cs --c --O1

mv $line.r1cs r1cs/$line$aux1.r1cs
mv $line.sym r1cs/$line$aux1.sym

cd $line$auxc
make
./$line ../witness/input.json ../witness/result$aux1.wtns
cd ..
/home/clara/circom/circom_lucas/target/release/circom $line.circom --sym --r1cs --c --O2

mv $line.r1cs r1cs/$line$aux2.r1cs
mv $line.sym r1cs/$line$aux2.sym

cd $line$auxc
make
./$line ../witness/input.json ../witness/result$aux2.wtns
cd ..
rm -r $line$auxc
rm -r $line$auxw
rm log_input_signals.txt
rm log_input_signals_new.txt

