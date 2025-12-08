filename=$1
auxcvm="_cvm" 
aux0="_O0"
aux1="_O1"
aux2="_O2"

echo "Executing CVM witness check" > difs.txt

while read line; do
cd $line

ls > "names.txt"
while read line; do
if [[ "$line" = "names.txt" || "$line" = "fails" || $line = "circuits" ]]; then
echo "Not entering in case $line"
else
cd $line

ls > "names.txt"

while read circuit; do
if [[ "$circuit" = "names.txt" ]]; then 
echo "Not entering in case $circuit"
else
cd $circuit

echo "Executing circuit " $circuit >> ../../../difs.txt

/home/clara/circom/circom_cvm/target/release/circom $circuit.circom --cvm --O0

/home/clara/circom/circom-witnesscalc/target/release/cvm-compile $circuit$auxcvm/$circuit.cvm --wtns out.wtns --inputs witness/input.json

diff out.wtns witness/result_O0.wtns >> ../../../difs.txt

/home/clara/circom/circom_cvm/target/release/circom $circuit.circom --cvm --O1

/home/clara/circom/circom-witnesscalc/target/release/cvm-compile $circuit$auxcvm/$circuit.cvm --wtns out.wtns --inputs witness/input.json

diff out.wtns witness/result_O1.wtns >> ../../../difs.txt

/home/clara/circom/circom_cvm/target/release/circom $circuit.circom --cvm --O2

/home/clara/circom/circom-witnesscalc/target/release/cvm-compile $circuit$auxcvm/$circuit.cvm --wtns out.wtns --inputs witness/input.json

diff out.wtns witness/result_O2.wtns >> ../../../difs.txt

rm -r $circuit$auxcvm
rm out.wtns

cd ..
fi;
done < "names.txt"
rm "names.txt"

cd ..
fi;
done < "names.txt"
rm "names.txt"

cd ..
done < $filename
