// Tema: STL list
// Autor: Pavol Marak

// Poznamky:
//
// Kontajner 'list' je vhodny kontajner pre caste pridavanie
// vymazavanie z lubovolneho miesta, su to operacie v konstantnom
// case. Na druhej strane tento typ kontajnera neumoznuje priamy
// pristup k prvkom pomocou []. Pristup k prvkom je mozny len cez
// iterator.
//
// Vyhody:
// * rychle pridavanie/odstranovanie z lubovolneho miesta

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <list>

using namespace std;

// testovacia funkcia pre STL list
void test_stl_list() {
    // konstrukcia a inicializacia zoznamu
    list<int> cisla(10, 1); // vyplni 10 cislami a kazde bude mat hodnotu 1

    // odstranenie posledneho prvku
    cisla.pop_back();

    // odstranenie prveho prvku
    cisla.pop_front();

    // pridanie do zoznamu na koniec
    cisla.push_back(2);

    // pridanie do zoznamu na zaciatok
    cisla.push_front(0);

    // pristup k prvemu prvku
    cout << "Prvy prvok zoznamu: " << cisla.front() << endl;
    cout << endl << "Posledny prvok zoznamu: " << cisla.back() << endl;

    // obratenie poradia prvkov
    cisla.reverse();

    // odstranenie vsetkych vyskytov zadanej hodnoty
    cisla.remove(1);

    // merge - spojenie zotriedenych zoznamov do jedneho
    list<int> zoznam1{5, 8, 12};
    list<int> zoznam2{-9, 100};
    zoznam1.merge(zoznam2); // zoznam2 zostane prazdny

    // odstranenie vsetkych prvkov
    cisla.clear();
}


int main() {
    cout << endl << "STL list" << endl;
    cout << "........................." << endl << endl;
    test_stl_list();
    return 0;
}
