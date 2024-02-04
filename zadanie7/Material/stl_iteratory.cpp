// Tema: STL iteratory
// Autor: Pavol Marak

// Poznamky:
// STL iteratory sluzia na spristupnovanie prvkov
// vo vnutri kontajnerov. Podla toho ake typy operacii
// mozeme s iteratorom vykonavat ich rozdelujeme na:
//  * random access iterator
//  * bidirectional iterator
//  * forward iterator
//  * input iterator
//  * output iterator
//
// Pri ziskavani iteratorov z roznych typov kontajnerov si
// vzdy musime davat pozor o aky typ iteratora sa jedna.
// Napriklad kontajner list a iterator vrateny jeho metodou
// begin() je typu 'bidirectional', to znamena, ze ho vieme
// inkrementovat/dekrementovat, ale nevieme pomocou neho
// skocit na lubovolne miesto, t.j. iterator+n
//
// Od standardu C++20 bude zavedeny novy system iteratorov
// vid https://en.cppreference.com/w/cpp/iterator

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>

using namespace std;

// testovacia funkcia pre STL iteratory (kontajner vector)
void test_stl_iteratory_vector() {
    vector<int> cisla{74, 2, 32, 4, 5};

    // prechod vektorom pomocou iteratora
    cout << "Vypis kontajneru 'vector' pomocou iteratora:" << endl;
    vector<int>::iterator vector_it;
    for (vector_it = cisla.begin(); vector_it != cisla.end(); vector_it++) {
        cout << " " << *vector_it << endl;
    }
    cout << endl;

    // pridanie prvku do kontajnera 'vector' na poziciu 2.
    vector<int>::iterator ins_it = cisla.begin();
    cisla.insert(ins_it + 2, 999);

    // vymazanie prvku z kontajnera 'vector'
    cisla.erase(cisla.begin() + 3); // vymazanie prvku na pozicii 3

    // pozicne porovnavanie iteratorov (plati pre random acces iteratory)
    vector<int>::iterator it1 = cisla.begin();
    vector<int>::iterator it2 = cisla.begin() + 1;
    if (it1 < it2) {
        cout << "Iterator 'it1' (" << *it1 << ") ukazuje v kontajneri viac vlavo ako iterator 'it2' (" << *it2 << ")"
             << endl;
    } else {
        cout << "Iterator 'it2'(" << *it2 << ") ukazuje v kontajneri viac vlavo ako iterator 'it1' (" << *it1 << ")"
             << endl;
    }
}

// testovacia funkcia pre STL iteratory (kontajner list)
void test_stl_iteratory_list() {
    list<string> mena{"Anton", "Juraj", "Sona", "Klara", "Richard"};

    // prechod zoznamom pomocou iteratora
    cout << endl << "Vypis kontajneru 'list' pomocou iteratora:" << endl;
    list<string>::iterator list_it;
    for (list_it = mena.begin(); list_it != mena.end(); list_it++) {
        cout << " " << *list_it << endl;
    }

    // prechod zoznamom pomocou reverzneho iteratora
    cout << endl << "Vypis kontajneru 'list' pomocou reverzneho iteratora:" << endl;
    list<string>::reverse_iterator list_rit;
    for (list_rit = mena.rbegin(); list_rit != mena.rend(); list_rit++) {
        cout << " " << *list_rit << endl;
    }

    // pridanie prvku do kontajnera 'list' na poziciu 2
    list<string>::iterator ins_it = mena.begin();
    // ins_it +=2; // toto nemozeme urobit, pretoze tento iterator nie je typu random access
    ins_it++;
    ins_it++;
    mena.insert(ins_it, "Nove meno");

    // vymazanie prvku z kontajnera 'list'
    mena.erase(mena.begin()); // vymazanie prveho prvku
    mena.erase(--mena.end()); // vymazanie posledneho prvku
    // mena.erase(mena.end()); // chyba
}

// testovacia funkcia pre STL iteratory (kontajner map)
void test_stl_iteratory_map() {
    map<int, string> mapa{
            {1, "jeden"},
            {2, "dva"},
            {3, "tri"}
    };

    // prechod mapou pomocou iteratora
    cout << endl << "Vypis kontajneru 'map' pomocou iteratora:" << endl;
    map<int, string>::iterator map_it;
    for (map_it = mapa.begin(); map_it != mapa.end(); map_it++) {
        cout << " " << (*map_it).first << " -> " << (*map_it).second << endl;
    }

    // vymazanie prvku z mapy
    map_it = mapa.find(2); // vrati sa iterator na prvok, kde je 2 klucom
    mapa.erase(map_it);
}

int main() {
    cout << endl << "STL iteratory" << endl;
    cout << "........................." << endl << endl;
    test_stl_iteratory_vector();
    test_stl_iteratory_list();
    test_stl_iteratory_map();
    return 0;
}
