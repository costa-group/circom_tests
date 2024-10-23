// Simple case, same buses for all the elements in the heterogeneus array of components
// Choose n,m,l to make the array homogeneus or heterogeneus

bus Simple(){
    signal a;
    signal b;
}


template A(n){
    Simple input in;
    Simple output out;
    
    if (n % 2 == 0){
        out <== in;
    } else{
        out.a <== in.b;
        out.b <== in.a;
    }

}


template B(n){
    Simple input in[3];
    Simple output out[3];
    
    for (var i = 0; i < 3; i++){
        out[i] <== A(n[i])(in[i]);
    }

}


component main = B([2, 2, 2]);


