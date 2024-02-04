// Tema: STL deque
// Autor: Pavol Marak

// Poznamky:
//
// Kontajner 'deque' je vhodny kontajner pre situacie, kde
// pridavanie a odstranovanie prvkov prebieha len koncoch.
// Ponuka taktiez nahodny pristup k prvku pomocou [].
//
// Vyhody:
// * rychle pridavanie/odstranovanie z oboch koncov

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <deque>

using namespace std;

// testovacia funkcia pre STL deque
void test_stl_deque() {
    // konstrukcia a inicializacia obojsmernej fronty
    deque<char> pismena{'R', 'z', 'q', 'W', 'A'};

    // vypis obsahu fronty cez operator [] alebo metodu at()
    cout << "Obsah obojsmernej fronty: " << endl;
    for (size_t i = 0; i < pismena.size(); i++) {
        cout << " [" << i << "] " << pismena[i] << endl;
        //cout << " [" << i << "] " << pismena.at(i) << endl;
    }

    // pristup k prvemu prvku obojsmernej fronty
    cout << endl << "Prvy prvok (front): " << pismena.front() << endl;

    // pristup k poslednemu prvku obojsmernej fronty
    cout << endl << "Posledny prvok (back): " << pismena.back() << endl;

    // pridanie prvku na zaciatok
    pismena.push_front('f');

    // pridanie prvku na koniec
    pismena.push_back('b');

    // vymazanie vsetkych prvkov
    pismena.clear();

    // FIFO styl pridavania/vyberania prvkov
    // FIFO: First In First Out
    int n = 5;
    cout << endl << "Poradie pridavania (push_back):" << endl;
    for (int i = 0; i < n; i++) {
        pismena.push_back('a' + i);
        cout << " " << pismena.back();
    }
    cout << endl << endl << "Poradie vyberania (pop_front):" << endl;
    while (!pismena.empty()) {
        cout << " " << pismena.front();
        pismena.pop_front();
    }
    cout << endl;
}

int main() {
    cout << endl << "STL deque" << endl;
    cout << "........................." << endl << endl;
    test_stl_deque();
    return 0;
}
