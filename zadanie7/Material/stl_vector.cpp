// Tema: STL vector
// Autor: Pavol Marak

// Poznamky:
//
// Kontajner 'vector' predstavuje dynamicke pole.
// Je rychly pri nahodnom pristupovani k prvkom.
// Takisto je relativne rychle pridavanie/odstranovanie
// prvkov z konca. Nevyhodou je pomale pridavanie/odstranovanie
// zo stredu kontajnera.
//
// Vyhody:
// * rychly pristup cez [] alebo at()
// * relativne rychla operacia push_back()

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// definicia vlastnej triedy reprezentujucej film
class Film {
    string nazov;
    string zaner;
    int hodnotenie;
    int rok;
public:
    // default konstruktor
    Film() : hodnotenie(0), rok(-1) {}

    // parametricky konstruktor
    Film(const string &nazov, const string &zaner,
         const int hodnotenie, const int rok)
            : nazov(nazov), zaner(zaner), hodnotenie(hodnotenie), rok(rok) {}

    // metoda na vratenie textovej reprezentacie filmu
    string toString() const {
        return nazov +
               ", " +
               zaner +
               ", " +
               to_string(hodnotenie) +
               "% , " +
               to_string(rok);
    }

    // getter pre atribut 'rok'
    int getRok() const {
        return rok;
    }

    // getter pre atribut 'hodnotenie'
    int getHodnotenie() const {
        return hodnotenie;
    }

    // getter pre atribut 'nazov'
    string getNazov() const {
        return nazov;
    }
};

// pretazenie operatora << kvoli vypisu filmu
ostream &operator<<(ostream &out, const Film &film) {
    return out << film.toString();
}

// pretazenie operatora << kvoli vypisu vektora filmov
ostream &operator<<(ostream &out, const vector<Film> &db) {
    for (size_t i = 0; i < db.size(); i++) {
        out << " [" << i << "] " << db[i] << endl;
    }
    return out;
}

// testovacia funkcia pre STL vector (verzia 1)
void test_stl_vector_1() {
    // konstrukcia a inicializacia vektora stringov
    vector<string> v1{"skola", "PT", "cvicenie", "prednaska"};

    // vypis obsahu vektora
    cout << "Obsah vektora: " << endl;
    for (size_t i = 0; i < v1.size(); i++) {
        cout << " [" << i << "] " << v1[i] << endl;
        // cout << " [" <<  i << "] " << v1.at(i) << endl;
    }

    // ziskanie smernika na dynamicke pole vo vnutri vektora
    string *v1_data = v1.data();
    cout << endl << "Obsah vektora (cez data()): " << endl;
    for (size_t i = 0; i < v1.size(); i++) {
        cout << " [" << i << "] " << v1_data[i] << endl;
    }

    // ziskanie poctu prvkov vo vektore
    cout << endl << "Velkost vektora: " << v1.size() << endl;

    // overenie ci je vektor prazdny
    cout << endl << "Je vektor prazdny? " << (v1.empty() ? "ano" : "nie") << endl;

    // vlozenie prvku na koniec
    v1.push_back("zapocet");

    // vymazanie posledneho prvku
    v1.pop_back();

    // rychle porovnanie 2 vektorov
    vector<string> v2{"abcd"};
    cout << endl << "Vektory v1 a v2 " << ((v1 == v2) ? "su" : "nie su") << " rovnake" << endl;

    // vymazanie obsahu vektora
    v1.clear();
    v2.clear();
}

// testovacia funkcia pre STL vector (verzia 2)
void test_stl_vector_2() {
    // vektor objektov typu 'Film'
    vector<Film> db{
            {"Interstellar",           "scifi",       84, 2014},
            {"Patriot",                "vojnovy",     69, 2000},
            {"Death Wish",             "akcny",       65, 2018},
            {"Hlada sa Dory",          "animovany",   73, 2016},
            {"Wall-E",                 "animovany",   85, 2008},
            {"Prometheus",             "scifi",       66, 2012},
            {"Maverick",               "komedia",     83, 1994},
            {"Tulak z vysokych plani", "western",     72, 1973},
            {"Southpaw",               "sportovy",    74, 2015},
            {"Creed 2",                "sportovy",    71, 2018},
            {"V zajati demonov",       "horor",       82, 2013},
            {"Creed 2",                "sportovy",    71, 2018},
            {"Polarny expres",         "animovany",   65, 2004},
            {"Zachrante vojaka Ryana", "vojnovy",     89, 1998},
            {"Tajomna rieka",          "mysteriozny", 81, 2003},
            {"Zelena mila",            "drama",       93, 1999},
            {"Titanic",                "drama",       85, 1997},
    };

    cout << "Obsah DB: " << endl << db;
    db.push_back({"Sam doma", "komedia", 86, 1990});

    // najdenie najstarsieho filmu
    Film oldest_movie = db[0];
    for (size_t i = 1; i < db.size(); i++) {
        if (db[i].getRok() < oldest_movie.getRok()) {
            oldest_movie = db[i];
        }
    }
    cout << endl << "Najstarsi film v DB: " << endl;
    cout << " " << oldest_movie << endl;

    // najdenie vsetkych filmov s hodnotenim v zadanom intervale
    int h_low = 80;
    int h_high = 90;
    cout << endl << "Filmy s hodnotenim <" << h_low << "," << h_high << ">:" << endl;
    for (size_t i = 0; i < db.size(); i++) {
        if (db[i].getHodnotenie() >= h_low && db[i].getHodnotenie() <= h_high) {
            cout << " " << db[i] << endl;
        }
    }

    // vytvorenie novej DB, ktora bude obsahovat
    // len filmy obsahujuce v nazve pismeno 't'
    vector<Film> nova_db;
    for (size_t i = 0; i < db.size(); i++) {
        if (db[i].getNazov().find('t') != string::npos) {
            nova_db.push_back(db[i]);
        }
    }
    cout << endl << "Nova DB (nazov filmu obsahuje znak 't'): " << endl << nova_db;
}

int main() {
    cout << endl << "STL vector (verzia 1)" << endl;
    cout << "........................." << endl << endl;
    test_stl_vector_1();
    cout << endl << "STL vector (verzia 2)" << endl;
    cout << "........................." << endl << endl;
    test_stl_vector_2();
    return 0;
}
