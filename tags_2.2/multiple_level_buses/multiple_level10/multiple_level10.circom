bus Bus1(){
    signal a[5];
    signal b[3];
}

bus Bus2(){
    signal {tag2} a;
    Bus1() {tag3} b[2];

}


template B(){
    Bus2() input {tag4} in;
    Bus1() output out <== in.b[1];
    
    in.b.tag3 === 5;
    in.tag4 === 99;
    
}

template D(){
    signal input {tag1} in;
    
    in.tag1 === 3;

}


template A(){

    signal input a[5];
    
    Bus1() {tag3} aux1[2];
    aux1.tag3 = 5;
    aux1[0].a <== a;
    aux1[1].a <== a;
    
    signal {tag1} s;
    s.tag1 = 3;
    s <== 1;
    
    signal {tag1} s2;
    s2.tag1 = 3;
    s2 <== 2;
    
    for (var i = 0; i < 3; i++){
        aux1[0].b[i] <== s;
        aux1[1].b[i] <== s2;
    }
    
    D()(aux1[1].b[0]);
    
    
    Bus2() {tag4} aux;
    aux.tag4 = 99;
    
    signal {tag2} s1;
    s1.tag2 = 7;
    s1 <== 99;
    
    aux.a <== s1;
    aux.b <== aux1;
    
    
    Bus1 output out <== B()(aux);
    
}


component main = A();
