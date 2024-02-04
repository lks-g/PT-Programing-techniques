#include <iostream>

void op1(){
    std::cout << "op1" << std::endl;
}

void op2(){
    std::cout << "op2" << std::endl;
}

void runOperation(void(*op)()){
    op();
}

int main() {
    runOperation(op1);
    runOperation(op2);
    return 0;
}

