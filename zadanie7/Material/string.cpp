// Tema: Trieda std::string
// Autor: Pavol Marak

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

// ODPORUCANY ZDROJ:
// http://www.cplusplus.com/reference/string/string/?kw=string
// https://en.cppreference.com/w/cpp/string/basic_string

// POZNAMKA: tento program si otestujte v Debug rezime
// pretoze nie vsetky casti kodu su vizualizovane vypisom
// do konzoly

int main() {
    // klasicky C retazec
    const char c_string[10] = "Ahoj";

    // Trieda 'std::string' zo standardnej kniznice C++

    // 1. konstruktory stringu
    string a1; // default konstruktor
    string a2("abcdefgh"); // z C retazca
    string a3(a2); // copy konstruktor
    string a4(a3, 1, 2); // substring konstruktor
    string a5(10, 'x'); // fill konstruktor

    // 2. kopirovanie stringov (hlboka kopia)
    // v jazyku C bolo treba pouzit funkciu strcpy()
    string b1("nieco");
    string b2;
    b2 = b1;
    // porovnanie adries stringov
    cout << (void *) b1.data() << endl << (void *) b2.data() << endl;

    // 3. operatory

    // operator +
    string c1 = "ABC";
    c1 = c1 + "D";
    cout << c1 << endl;

    // operator +=
    string c2 = "Ako sa";
    c2 += " mas?";
    cout << c2 << endl;

    // operator ==
    string c3 = "A";
    string c4 = "a";
    cout << (c3 == c4 ? "rovnake" : "rozne") << " stringy" << endl;

    // 4. velkost retazca, pristup k znakom
    string d1 = "dlhy retazec";
    cout << "Dlzka retazca: " << d1.length() << endl;
    // metoda at() kontroluje, ci pristupujeme k platnemu znaku
    cout << d1[3] << " = " << d1.at(3) << endl;

    // 5. insert, erase, clear
    string e1 = "Bslava";
    e1.insert(1, "rati");
    cout << e1 << endl;

    string e2 = "Ahqqqoj";
    e2.erase(2, 3);
    cout << e2 << endl;

    string e3 = "aaaaaa";
    e3.clear();
    cout << e3 << endl;

    // 6. podretazec, vyhladavanie
    string f1 = "Ahoj mama";
    cout << f1.substr(5) << endl;

    string f2 = "A very long text";
    cout << (f2.find("very") != string::npos ? "naslo sa" : "nenaslo sa") << endl;

    // 7. konverzia do C retazca
    string g1 = "C retazec";
    const char *text = g1.c_str();
    cout << text << endl;

    // 8. globalna funkcia 'to_string'
    string h1;
    h1 = to_string(1.2345);
    cout << h1 << endl;

    // 9. globalna funkcia 'getline'
    string i1;
    cout << "Zadajte text: ";
    // funkcia nacita text az po prvy vyskyt znaku '.'
    getline(cin, i1, '.');
    cout << "Nacitany text: " << i1 << endl;

    return 0;
}
