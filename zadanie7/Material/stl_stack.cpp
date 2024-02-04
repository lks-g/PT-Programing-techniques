// Tema: STL stack
// Autor: Pavol Marak

// Poznamky:
//
// Kontajner 'stack' pracuje tak, ze sa prvky pridavaju na jeden koniec
// kontajnera a z rovnakeho konca sa aj odstranuju, tzv. LIFO kontext.
//
// Vyhody:
// * rychle vkladanie/odstranovanie z vrcholu zasobnika (top)

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// testovacia funkcia pre STL stack
void test_stl_stack() {
    // konstrukcia prazdneho zasobnika
    stack<string> s;

    // ukazka LIFO kontextu prace zasobnika

    // pridavanie na vrchol zasobnika
    int n = 5;
    cout << "Poradie pridavania prvkov (push):" << endl;
    for (int i = 0; i < n; i++) {
        s.push(string(3, 'a' + i));
        cout << " " << s.top(); // vypis vrcholu zasobnika
    }

    // odoberanie prvkov z vrcholu zasobnika
    cout << endl << endl << "Poradie odstranovania prvkov (pop):" << endl;
    while (!s.empty()) {
        cout << " " << s.top(); // vypis vrcholu zasobnika
        s.pop();
    }
    cout << endl << endl;
}

int main() {
    cout << endl << "STL stack" << endl;
    cout << "........................." << endl << endl;
    test_stl_stack();
    return 0;
}
