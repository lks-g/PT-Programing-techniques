// Tema: smernik na funkciu (1. cast)

#include <iostream>

using namespace std;

int add(int a, int b) {
    return a+b;
}

int subtract(int a, int b) {
    return a-b;
}

int main() {
    int (*op)(int, int) = add;
    cout << op(10, 2) << endl;

    op = subtract;
    cout << op(10,2) << endl;

    return 0;
}
