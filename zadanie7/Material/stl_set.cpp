// Tema: STL set
// Autor: Pavol Marak

// Poznamky:
//
// Kontajner 'set' predstavuje usporiadanu mnozinu
// unikatnych a nemennych hodnot. Mnozina nedovoli
// pridanie duplikatov a zakazuje ich modifikaciu.
// Prvky mnoziny musia byt porovnatelne, t.j. bud
// su to zakladne datove typy alebo pre pouzivatelske
// typy musime mat k dispozicii vlastny porovnavaci
// funktor, funkciu alebo lambda vyraz, ktory vrati
// 'true' ak je prvok vlavo mensi ako prvok vpravo.
// Ked iterujeme cez mnozinu, prvky spristupnujeme
// implicitne v zotriedenom poradi.
//
// Vyhody:
// * vyhladavanie prvku v logaritmickom case

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

// testovacia funkcia pre STL set
void test_stl_set() {
    // konstrukcia prazdnej mnoziny
    set<int> mnozina;

    // pridavanie prvkov do mnoziny
    int n = 10, num;
    cout << "Pridavanie prvkov do mnoziny (insert):" << endl;
    for (int i = 0; i < n; i++) {
        num = rand() % 10;
        auto p = mnozina.insert(num); // vracia par, kde 'second' oznamuje uspesnost pridania
        cout << " Pridavam: " << num;
        if (!p.second) {
            cout << " (duplikat!!!)";
        }
        cout << endl;
    }

    // vypis mnoziny (pouzitim iteratora)
    cout << endl << "Vypis obsahu mnoziny (automaticky usporiadane prvky):" << endl;
    for (auto it = mnozina.begin(); it != mnozina.end(); it++) {
        cout << " " << *it << endl;
    }

    // vymazanie prvku z mnoziny
    size_t num_erased = mnozina.erase(5); // funkcia vrati pocet vymazanych prvkov
    cout << endl << "Prvok 5 " << (num_erased ? "bol" : "nebol") << " vymazany" << endl;

    // vyhladanie prvku
    auto result = mnozina.find(1);
    cout << endl << "Prvok 1 " << (result != mnozina.end() ? "bol" : "nebol") << " najdeny" << endl;

    // vymazanie obsahu mnoziny
    mnozina.clear();
}

int main() {
    srand((unsigned) time(nullptr));
    cout << endl << "STL set" << endl;
    cout << "........................." << endl << endl;
    test_stl_set();
    return 0;
}
