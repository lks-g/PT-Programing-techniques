#include <iostream>

void op1(){
    std::cout << "op1" << std::endl;
}

void op2(){
    std::cout << "op2" << std::endl;
}

typedef void (*fn)();


int main() {
    //void (*fns[])() = {op1,op2,op1};
    fn fns[] = {op1,op2,op1};
    for(fn f: fns){
    	f();
    }
    return 0;
}

