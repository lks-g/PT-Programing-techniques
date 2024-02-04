// Tema: STL priority_queue
// Autor: Pavol Marak

// Poznamky:
//
// Kontajner 'priority_queue' umoznuje velmi rychle ziskanie
// najvacsieho/najmensieho prvku (heap), ktory ako jediny
// vieme z kontajnera spristupnit. Po odstraneni maxima/minima
// vieme spristupnit druhy najvacsi/najmensi prvok, atd.
//
// Vyhody:
// * rychle ziskanie maxima/minima

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

// testovacia funkcia pre STL priority_queue
void test_stl_priority_queue() {
    // konstrukcia prazdnej prioritnej fronty
    priority_queue<int> pq;

    // pridavanie prvkov do prioritnej fronty
    int n = 10, num;
    cout << "Poradie pridavania prvkov do prioritnej fronty (push):" << endl;
    for (int i = 0; i < n; i++) {
        num = rand() % 100;
        pq.push(num);
        cout << " Pridavam: " << num << endl;
    }

    // odoberanie prvkov z prioritnej fronty (vzdy maximum)
    cout << endl << "Poradie odstranovania prvkov z prioritnej fronty (pop):" << endl;
    while (!pq.empty()) {
        cout << " Odstranujem: " << pq.top() << endl; // pristup k maximu
        pq.pop();
    }
}

int main() {
    srand((unsigned) time(nullptr));
    cout << endl << "STL priority_queue" << endl;
    cout << "........................." << endl << endl;
    test_stl_priority_queue();
    return 0;
}
