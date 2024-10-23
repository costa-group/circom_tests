pragma circom 2.2.0;

bus S(){
	signal {a} aux;
}

template A(){
	input S() {b} inter;

	inter.b === 2;
	output S() {b} out <== inter;
}

template B(){
	component a = A();
	S() {b} prueba; prueba.b = 2; prueba.aux <== 1;
	a.inter <== prueba;
	a.out.b === 2;
}

component main = B();
