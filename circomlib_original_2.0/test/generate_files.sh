#!/bin/bash
line=$1
auxc="_cpp" 
auxw="_js" 
aux0="_O0"
aux1="_O1"
aux2="_O2"

/home/clara/circom/circom_lucas/target/release/circom $line.circom --c --O0

cd $line$auxc
make
./$line ../witness/input.json ../witness/result$aux0.wtns
cd ..

/home/clara/circom/circom_lucas/target/release/circom $line.circom --c --O1

cd $line$auxc
make
./$line ../witness/input.json ../witness/result$aux1.wtns
cd ..
/home/clara/circom/circom_lucas/target/release/circom $line.circom --c


cd $line$auxc
make
./$line ../witness/input.json ../witness/result$aux2.wtns
cd ..
rm -r $line$auxc

