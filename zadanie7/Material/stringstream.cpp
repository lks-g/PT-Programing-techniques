// Tema: Trieda std::stringstream
// Autor: Pavol Marak

// Poznamky:
//
// Trieda 'stringstream' umoznuje vykonavat
// vstupno/vystupne operacie s retazcami.
// Je definovana v hlavickovom subore <sstream>.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// testovacia funkcia pre stringstream
void test_stringstream() {
    // konstrukcia a inicializacia stringstreamu
    stringstream my_stream_in{"This is a very short text stream"};

    // ziskanie celeho obsahu stringstreamu
    string stream_contents = my_stream_in.str();
    cout << "Obsah stringstreamu:" << endl << " " << stream_contents << endl;

    // formatovane citanie stringstreamu po slovach pomocou operatora >>
    string word;
    cout << endl << "Citanie stringstreamu po slovach (>>):" << endl;
    // pokial je stream v korektnom stave, tak citame
    while (my_stream_in >> word) {
        cout << " " << word << endl;
    }

    stringstream my_stream_out;

    // formatovany zapis do stringstreamu pomocou operatora <<
    cout << endl << "Zapis do stringstreamu (<<):" << endl;
    my_stream_out << "slovo ";
    my_stream_out << 1.0147;
    my_stream_out << ' ';
    my_stream_out << 100;
    cout << " " << my_stream_out.str() << endl;

    // kontrola, ci nedoslo k chybe citania kvoli zlemu formatu
    stringstream test_stream{"ahoj"};
    int a;
    test_stream >> a; // dojde k chybe, pretoze nesedi format
    if (test_stream.fail()) {
        cout << endl << "Doslo k chybe citania (zly ocakavany format)" << endl;
    }
}

int main() {
    cout << endl << "Trieda stringstream" << endl;
    cout << "........................." << endl << endl;
    test_stringstream();
    return 0;
}
