pragma circom 2.2.0;

bus S(){
	signal {a} aux;
}

template A(){
	input S() inter[3];
	input signal {b} aux2;
	//inter.b = 3;
}

template B(){
	component a = A();
	a.aux2.b = 3;
	a.aux2 <== 3;

}

component main = B();
