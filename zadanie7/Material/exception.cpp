// Tema: Vynimky
// Autor: Pavol Marak

#include <iostream>
#include <cstdio>

using namespace std;


// Vlastna vynimkova trieda.
class InvalidRectangleException {
private:
    const int a, b;
public:
    InvalidRectangleException(const int a, const int b) :
            a(a), b(b) {
    }

    // Metoda na vratenie textoveho popisu vynimky.
    const char *what() const {
        char *message = new char[100];
        sprintf(message, "(EXCEPTION) Invalid rectangle: a=%i, b=%i", a, b);
        return message;
    }
};

// Funkcia na vypocet obsahu obdlznika.
int rectangleArea(const int a, const int b) {
    // Ak je dlzka niektorej strany zaporna, vyhodi sa vynimka.
    if (a < 0 || b < 0) {
        throw InvalidRectangleException(a, b);
    }
    return a * b;
}

// Testovanie.
int main() {
    try {
        cout << rectangleArea(5, 3) << endl; // Nevznikne vynimka.
        cout << rectangleArea(-9, 10) << endl; // Vznikne vynimka.
    }
    // Exception handler pre vynimku typu InvalidRectangleException
    catch (InvalidRectangleException &e) {
        cout << e.what() << endl;
    }
    return 0;
}


