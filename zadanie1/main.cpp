/*
Meno a priezvisko: Lukas Grulik

POKYNY:
(1)  Subor premenujte na Priezvisko_Meno_ID_zadanie01.cpp (pouzite vase udaje bez diakritiky).
(2)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
(3)  Cela implementacia musi byt v tomto jednom subore.
(4)  Odovzdajte len tento (spravne premenovany) zdrojovy subor.
(5)  Program musi byt kompilovatelny.
(6)  Globalne a staticke premenne su zakazane.
(7)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
     (nemente nazvy, navratove hodnoty, ani typ a pocet parametrov v zadanych funkciach).
     Nemente implementacie zadanych datovych typov, ani implementacie hotovych pomocnych funkcii
     (ak nie je v zadani ulohy uvedene inak).
(8)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo datove typy.
(9)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo datovych typov).
     Testovaci kod ale nebude hodnoteny.
(10) Funkcia 'main' musi byt v zdrojovom kode posledna.
*/

#include <iostream>
#include <climits>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Pozicia v rovine
struct Position {
    int x; // x-ova suradnica
    int y; // y-ova suradnica
};

// Datum
struct Date {
    int year;  // rok
    int month; // mesiac
    int day;   // den
};

// Uspesnost vykonania funkcie
enum class Result {
    SUCCESS, // funkcia vykonana uspesne
    FAILURE  // chyba pri vykonavani funkcie
};

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia na standardny vystup vytlaci udaje v strukture.
    V implementacii musi byt pouzity 'std::cout'.

    Format tlace musi byt podla nasledujucich prikladov. Bez odriadkovania. Bez uvodzoviek. Dodrzte pouzitie medzier.
    Priklady:
        "x: 10, y: 20"
        "x: -12345, y: 2"

    PARAMETER:
        [in] position - pozicia, ktora bude vytlacena
*/
void print(const Position *position) {
    std::cout << "x: " << position->x <<  ", y: " << position->y;
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Implementujte rovnaku funkcionalitu ako v prvom priklade. Rozdiel je len typ parametra funkcie.
*/
void print(const Position &position) {
    cout << "x: " << position.x <<  ", y: " << position.y;
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia zo standardneho vstupu nacita postupne dve cisla. Ulozi ich ako x-ovu a y-ovu zlozku pozicie 'position'.
    V implementacii musi byt pouzity 'std::cin' a formatovany vstup.

    PARAMETER:
        - [out] position - pozicia, ktorej hodnoty sa nastavia podla udajov zo standardneho vstupu.

    VSTUPNE PODMIENKY:
        Text zadany na standardny vstup obsahuje dve cele cisla, ktore mozno reprezetovat typom 'int'.
        Nemusite osetrovat moznost chybnych udajov na standardnom vstupe.
 */
void readFromStandardInput(Position *position) {
    std::cin >> position->x >> position->y;
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati najvacsiu hodnotu prvku pola 'data' a nastavi 'result' podla uspesnosti hladania.

    Ak pole obsahuje prvky, tak vrati ich maximum a nastavi 'result' na 'SUCCESS'.
    Ak pole neobsahuje ziadne prvky (jeho dlzka je nulova),
    tak vrati minimalnu hodnotu, ktoru moze reprezentovat datovy typ 'int' a nastavi result na 'FAILURE'.

    PARAMETRE:
        [in] data    - adresa zaciatku pola
        [in] length  - pocet prvkov pola (dlzka pola)
        [out] result - indikuje uspesnost najdena maxima

    NAVRATOVA HODNOTA:
        Ak pole obsahuje prvky, tak vrati hodnotu najvacsieho prvku pola 'data'.
        Ak pole neobsahuje prvky, tak vrati minimalnu hodnotu reprezentovatelnu datovym typom 'int'.

    PRIKLADY:
        vstup: (1, 2, 5, 0, 1) => navratova hodnota: 5,  result: 'Result::SUCCESS'
        vstup: (-5, -2, -10)   => navratova hodnota: -2, result: 'Result::SUCCESS'
        vstup: () => navratova hodnota: minimalna hodnota reprezentovatelna datovym typom 'int', result: 'Result::FAILURE'
*/
int maximum(const int *data, std::size_t length, Result *result) {

    int max = INT_MIN;
    std::size_t i;

    if (length == 0)
    {
        *result = Result::FAILURE;
        //max = INT_MIN;
        return INT_MIN;
    }

    for(i = 0; i < length; i++)
    {
        if (max <= data[i]){
            max = data[i];
        }
    }

    *result = Result::SUCCESS;

    return max; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati pocet znakov, ktore su potrebne na zapis cisla 'value' (v desiatkovej ciselnej sustave).

    PARAMETER:
        - [in] value - analyzovana hodnota

    NAVRATOVA HODNOTA:
        Pocet znakov, potrebnych pre textovu reprezentaciu hodnoty 'value'

    PRIKLADY:
        - vstup: 18002 => vystup: 5
        - vstup: 2     => vystup: 1
        - vstup: 0     => vystup: 1
        - vstup: -500  => vystup: 4
*/
int numDigits(int value) {

    int len = 0;
    string result = to_string(value);

    for(int i = 0; result[i] != '\0'; i++)
        len++;

    return len; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 6. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytlaci na standardny vystup datum, podla zadaneho formatu.

    Vytlaceny text bude obsahovat kopiu textu vo 'format', ale
    znak 'D' nahradi dnom,
    znak 'M' nahradi mesiacom,
    znak 'Y' nahradi rokom v datume.

    PARAMETRE:
        - [in] date - datum
        - [in] format - format vylacenia datumu

    PRIKLADY:
        Nech datum je 10. aprila 2020
        - format: "D. M. Y" => "10. 4. 2020"
        - format: "D. M."   => "10. 4."
        - format: "Pisomka bude D. M. Y, v miestnosti BC 300" => "Pisomka bude 10. 4. 2020, v miestnosti BC 300"
        - format: "M/D/Y"   => "4/10/2020"
        - format: "Y-M-D"   => "2020-4-10"

    POZNAMKA:
        Vsimnite si pretazenie funkcie. Tento zdrojovy subor obsahuje 3 funkcie s nazvom 'print'.
*/
void print(const Date *date, const char *format) {

    std::string copy = format;
    int len = copy.length();

    for(int i = 0; i < len; i++)
    {
        if      (copy[i] == 'D') { std::cout << date->day;  }
        else if (copy[i] == 'M') { std::cout << date->month;}
        else if (copy[i] == 'Y') { std::cout << date->year; }
        else                     { std::cout << copy[i];    }
    }
}

//-------------------------------------------------------------------------------------------------
// 7. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori novy datum podla parametrov a vrati jeho adresu.
    Pre dynamicku alokaciu pamate pouzite operator 'new'.

    PARAMETRE:
        [in] day   - den v datume
        [in] month - mesiac v datume
        [in] year  - rok v datume

    NAVRATOVA HODNOTA:
        Adresa na dynamicky alokovany datum, ktoreho obsah je dany parametrami
*/
Date* create(int day, int month, int year) {

    Date* date  = new Date;
    date->day   = day;
    date->month = month;
    date->year  = year;

    return date; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 8. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia dealokuje datum. Smernik na datum nastavi na 'nullptr'.
    Na dealokaciu pamate pouzite operator 'delete'.

    PARAMETER:
        [in, out] date - adresa smernika na datum

    VYSTUPNE PODMIENKY:
        Datum na adrese (*date) je dealokovany.
        (*date) ma hodnotu 'nullptr'.
*/
void destroy(Date **date) {
    delete *date;
    *date = nullptr;
}

//-------------------------------------------------------------------------------------------------
// 9. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia zisti, ci je rok v datume priestupny.

    PARAMETER:
        [in] date - datum

    NAVRATOVA HODNOTA:
        'true'  - ak rok je priestupny
        'false' - ak rok nie je priestupny

    VSTUPNA PODMIENKA:
        Rok v datume je kladne cislo

    URCENIE PRIESTUPNEHO ROKU:
        Rok delitelny cislom 4 je priestupny okrem pripadu, ked je delitelny cislom 100, ale nie je delitelny cislom 400.
        Priklady:
            - priestupne roky: 2000, 2004, 2008
            - nepriestupne roky: 2001, 2002, 2003, 2005, 2006, 2007, 2009, 2010
            - priestupne roky: 1600, 2000, 2400
            - nepriestupne roky: 1500, 1700, 1800, 1900, 2100, 2200, 2300, 2500
*/
bool isInLeapYear(const Date *date) {

    if (date->year % 400 == 0) return true;
    if (date->year % 400 == 1) return false;
    if (date->year % 100 == 0) return false;
    if (date->year % 4   == 0) return true;

    return false;
}

//-------------------------------------------------------------------------------------------------
// 10. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia zisti, ci je datum platny.

    Treba overit, ci datum moze existovat. Napriklad
    v januari moze byt den od 1 do 31,
    vo februari od 1 do 28 alebo 29, podla toho, ci je rok priestupny.
    Rok ma mesiac 1 az 12.

    PARAMETER:
        [in] date - datum

    NAVRATOVA HODNOTA:
        'true'  - ak datum je platny
        'false' - ak datum nie je platny

    VSTUPNA PODMIENKA:
        Rok v datume je kladne cislo
*/
bool isValid(const Date *date) {

    if (date->day < 1 || date->day > 31 || date->month < 1 || date->month > 12 || date->year < 1){
        return false;}
    else if (date->month != 8 && (date->month == 4 || date->month == 6 || date->month == 9 || date->month == 11) && date->day > 30){
        return false;}
    else if (date->month == 2 && isInLeapYear(date) && date->day > 29){
        return false;}
    else if (date->month == 2 && !isInLeapYear(date) && date->day > 28){
        return false;}

    return true;
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne testovacie funkcie a struktury

int main() {

    //create(15,5,2006);

    //Position position;
    //position.x = 10;
    //position.y = 20;
    //print(position);
    //print(&position);

    //int value = 0;
    //std::cin  >> value;
    //std::cout << numDigits(value);

    //const int data[100] = {};
    //Result result;
    //std::cout << maximum(data, 3, &result);

    //Date *date;
    //date->day = 10;
    //date->month = 8;
    //date->year = 2001;
    //const char* format = {"Pisomka bude D. M. Y, v miestnosti BC 300"};
    //print(&date, format);

    //destroy(&date);

    //std::cin >> date.year;
    //isInLeapYear(&date);

    Date date;
    std::cin >> date.day;
    std::cin >> date.month;
    std::cin >> date.year;
    isValid(&date);

    return 0;
}
