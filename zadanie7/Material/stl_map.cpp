// Tema: STL map
// Autor: Pavol Marak

// Poznamky:
//
// Kontajner 'map' predstavuje usporiadanu kolekciu
// 'key-value' parov. Prvky su usporiadane podla klucov.
// Kluce su nemenne a unikatne. Do mapy nie je mozne
// pridat prvky s rovnakym klucom. Prvky mapy musia
// byt porovnatelne, teda musi byt jasne, za akych
// podmienok je prvok vlavo mensi ako prvok vpravo.
// Pre zakladne datove typy je porovnatelnost automaticka
// avsak pre pouzivatelske typy musime dodat vlastny
// porovnavaci funktor, funkciu alebo lambdu.
// Ked iterujeme cez mapu, prvky spristupnujeme implicitne
// v usporiadanom poradi.
//
// Vyhody:
// * vyhladavanie prvku v logaritmickom case

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>
#include <string>

using namespace std;

// testovacia funkcia pre STL map
void test_stl_map() {
    // konstrukcia a inicializacia mapy
    map<string, string> slovnik{
            {"nadej",  "hope"},
            {"pribeh", "story"},
            {"hra",    "game"},
            {"poklad", "treasure"},
            {"clovek", "man"},
            {"noc",    "night"},
            {"film",   "movie"}
    };

    // vypis mapy (cez iterator)
    cout << "Vypis mapy (cez iterator):" << endl;
    for (auto it = slovnik.begin(); it != slovnik.end(); it++) {
        cout << " " << (*it).first << " -> " << (*it).second << endl;
    }
    cout << endl;

    // pridavanie prvkov do mapy
    auto p1 = slovnik.insert({"film", "movie"}); // pokus o pridanie duplikatu
    cout << "Pridavam {\"film\",\"movie\"} ... ";
    if (!p1.second) {
        cout << " NEPRIDANE (duplikat)";
    } else {
        cout << " PRIDANE";
    }
    cout << endl << endl;

    auto p2 = slovnik.insert({"vietor", "wind"}); // pridanie noveho prvku
    cout << "Pridavam {\"vietor\",\"wind\"} ... ";
    if (!p2.second) {
        cout << " NEPRIDANE (duplikat)";
    } else {
        cout << " PRIDANE";
    }
    cout << endl << endl;

    // vymazavanie z mapy
    size_t n = slovnik.erase("poklad");
    cout << "Prvok s klucom \"poklad\" " << (n ? "bol" : "nebol") << " vymazany" << endl << endl;

    // pristup k namapovanej hodnote
    string r1 = slovnik["clovek"];

    // rychle pridanie do mapy pomocou []
    slovnik["duha"] = "rainbow";

    // aktualizacia namapovanej hodnoty pomocou []
    slovnik["pribeh"] = "tale";

    // vyhladanie prvku
    auto r2 = slovnik.find("nadej");
    cout << "Prvok s klucom \"nadej\" " << (r2 != slovnik.end() ? "bol" : "nebol") << " najdeny" << endl << endl;

    // vymazanie obsahu mapy
    slovnik.clear();
}

int main() {
    cout << endl << "STL map" << endl;
    cout << "........................." << endl << endl;
    test_stl_map();
    return 0;
}
