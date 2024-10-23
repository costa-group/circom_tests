// Simple case, array of buses as inputs, different sizes in the arrays
// The bus contains other buses
// Choose n,m,l to make the array homogeneus or heterogeneus

bus Simple(){
    signal a;
    signal b;
}

bus Simple1(){
    signal a;
}

bus Compuesto(){
    signal a;
    Simple1 b;
    Simple c;
}


template A(n){
    Compuesto input in[n];
    Compuesto output out[n];
    
    if (n % 2 == 0){
        out <== in;
    } else{
        for (var i = 0; i < n; i++){
           out[i].a <== in[i].a;
           out[i].b <== in[i].b;
           out[i].c.a <== in[i].c.b;
           out[i].c.b <== in[i].c.a;
        }
    }

}


template B(n1, n2, n3){
    Compuesto input in1[n1];
    Compuesto input in2[n2];
    Compuesto input in3[n3];
    Compuesto output out[3];
    
    var sizes[3] = [n1, n2, n3];
    
    component aux[3];
    
    for (var i = 0; i < 3; i++){
        aux[i] = A(sizes[i]);
        for (var j = 0; j < sizes[i]; j++){
           if (i == 0){
                aux[i].in[j] <== in1[j];
           } else if (i == 1){
                aux[i].in[j] <== in2[j];
           } else{
                aux[i].in[j] <== in3[j];
           }
        }
        out[i] <== aux[i].out[0];
    }

}


component main = B(5, 4, 2);


