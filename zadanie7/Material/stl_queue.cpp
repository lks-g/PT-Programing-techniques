// Tema: STL queue
// Autor: Pavol Marak

// Poznamky:
//
// Kontajner 'queue' pracuje tak, ze sa prvky pridavaju na jeden
// koniec (back) a z opacneho konca sa odoberaju (front), tzv. FIFO
// kontext.
//
// Vyhody:
// * rychle vkladanie na koniec fronty
// * rychle odstranenie zo zaciatku fronty

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

// testovacia funkcia pre STL queue
void test_stl_queue() {
    // konstrukcia prazdnej fronty
    queue<int> fronta;

    // ukazka FIFO kontextu fronty

    // pridavanie prvkov do fronty
    int n = 10;
    cout << "Poradie pridavania prvkov do fronty (push):" << endl;
    for (int i = 0; i < n; i++) {
        fronta.push(i);
        cout << " Pridavam: " << fronta.back() << endl; // pristup k poslednemu prvku vo fronte
    }

    // odoberanie prvkov z fronty
    cout << endl << "Poradie odstranovania prvkov z fronty (pop):" << endl;
    while (!fronta.empty()) {
        cout << " Odstranujem: " << fronta.front() << endl; // pristup k prvemu prvku fronty
        fronta.pop();
    }
}

int main() {
    cout << endl << "STL queue" << endl;
    cout << "........................." << endl << endl;
    test_stl_queue();
    return 0;
}
