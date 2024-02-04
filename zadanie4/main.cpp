/*
Meno a priezvisko: Lukas Grulik

POKYNY:
(1)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
(2)  Cela implementacia musi byt v tomto jednom subore.
(3)  Odovzdajte len tento zdrojovy subor (dopleny o riesenia).
(4)  Program musi byt kompilovatelny.
(5)  Globalne a staticke premenne su zakazane.
(6)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
     (nemente nazvy, navratove hodnoty, ani typ a pocet parametrov v zadanych funkciach).
     Nemente implementacie zadanych datovych typov, ani implementacie hotovych pomocnych funkcii
     (ak nie je v zadani ulohy uvedene inak).
(7)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo datove typy.
(8)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo datovych typov).
     Testovaci kod ale nebude hodnoteny.
(9) Funkcia 'main' musi byt v zdrojovom kode posledna.
*/

#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Hmotnost produktu a obalu. Hmotnost zabaleneho produktu je suctom obidvoch zloziek
struct Weight {
    int product; // hmotnost produktu
    int packing; // hmotnost balenia
};

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada pole 'data', od najvacsieho prvku po najmensi.
    Pouzite algoritmus bubble sort.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada
        [in] length    - pocet prvkov pola

    VSTUPNA PODMIENKA:
        ak 'length' > 0, tak 'data' ukazuje na platne pole

    PRIKLADY:
        {1, 3, 2} -> {3, 2, 1}
        {1, 2, 2, 1} -> {2, 2, 1, 1}
        {1} -> {1}
        {} -> {}
*/
void bubbleSort(int *data, const size_t length) {

    size_t i, j, tmp;

    if (length <= 0) {return;}

    for(i = 1; i < length; i++){
        for(j = 0; j < length - i; j++)
        {
            if(data[j] < data[j+1])
            {
                tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada pole 'data' podla celkovej hmotnosti zabaleneho tovaru, t.j. podla suctu zloziek ('product' a 'packing').
    Poradie usporiadania je od najtazsieho zabaleneho tovaru po najlahsi zabaleny tovar.
    Pouzite algoritmus bubble sort.

    Podmienka porovnania struktur:
    Pri porovnavani prvkov funkcia scita hodnoty 'product' a 'packing' oboch porovnavanych struktur.
    Struktury s vacsim suctom zloziek budu po usporiadani pred strukturami s mensim suctom zloziek.

    Vzajomne usporiadanie struktur s rovnakym suctom poloziek:
    Pri bodovom hodnoteni nezalezi na vzajomnom usporiadani struktur s rovnakym suctom poloziek (aj ked hodnoty poloziek mozu byt rozne).
    Lepsie je vsak implementovat stabilne triedenie (struktury s rovnakym suctom poloziek nemenia vzajomne usporiadanie).

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada
        [in] length    - pocet prvkov pola

    VSTUPNA PODMIENKA:
        ak 'length' > 0, tak 'data' ukazuje na platne pole

    PRIKLADY:
        {{10, 1}, {20, 2}, {5, 2}} -> {{20, 2}, {10, 1},{5, 2}} pretoze 20+2=22, 10+1=11, 5+2=7 a 22 > 11 > 7
        {{11, 1}, {2, 1}, {10, 2}, {15, 7}} -> {{15, 7}, {11, 1}, {10, 2}, {2, 1}}
        {} -> {}

    POZNAMKA:
        Priklady jednoducheho vytvorenia pola v testovacom kode:
        Weight baliky[] = {{10, 1}, {20, 2}, {5,2}};
        Weight baliky[] = {{.product = 10, .packing = 1}, {.product = 20, .packing = 2}, {.product = 5, .packing = 2}}; // od C++ 20
*/
void bubbleSort(Weight *data, const size_t length) {

    Weight tmp;                 // Pomocna premenna na vykonanie swapu
    size_t i,j, wght1, wght2;   // Pomocna premenna pre weight

    for(i = 1; i < length; i++){
        for(j = 0; j < length - i; j++)
        {
            wght1 = data[j].product + data[j].packing;
            wght2 = data[j+1].product + data[j+1].packing;

            if(wght1 < wght2)
            {
                tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vyberie pivota a vrati jeho index.
    Pivota vyberie ako median prvkov:
      - data[low]
      - data[(high+low)/2]
      - data[high-1]

    PARAMETRE:
        [in] data - pole, v ktoreho casti s indexami 'low' ... 'high'-1, funkcia vybera pivot
        [in] low  - index prveho prvku casti pola, v ktorej funkcia hlada pivot
        [in] high - index za poslednym prvkom casti pola, v ktorej funkcia hlada pivot

    NAVRATOVA HODNOTA:
        index pivota

    VSTUPNE PODMIENKY:
        'data' ukazuje na platne pole
        'low' < 'high'

    PRIKLADY:
        data: {10, 20, 2000, 30, 1000, 40, 5000, 50, 60, 70}, low: 2, high: 7 -> return 2
        data: {10, 20, 1000, 30, 2000, 40, 5000, 50, 60, 70}, low: 2, high: 7 -> return 4
        data: {10, 20, 5000, 30, 1000, 40, 2000, 50, 60, 70}, low: 2, high: 7 -> return 6

        data: {10, 20, 1000, 30, 40, 2000, 50, 5000, 60, 70}, low: 2, high: 8 -> return 5

        data: {10, 20, 1000, 2000, 30, 40, 50},               low: 2, high: 4 -> return 3
        data: {10, 20, 2000, 1000, 30, 40, 50},               low: 2, high: 4 -> return 3

        data: {10, 20, 1000, 30, 40},                         low: 2, high: 3 -> return 2
*/
size_t getPivotIndex(const int *data, const size_t low, const size_t high)
{
    size_t middle = (high + low) / 2;
    size_t lw  = data[low];     // Low
    size_t mid = data[middle];  // Middle
    size_t hgh = data[high-1];  // High

    if (lw  <= mid && lw >= hgh) {return low;   }
    if (lw  >= mid && lw <= hgh) {return low;   }
    if (mid <= lw && mid >= hgh) {return middle;}
    if (mid >= lw && mid <= hgh) {return middle;}
    else                         {return high-1;}
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vykona partition (cast algoritmu quick sort) a vrati novy index pivota.
    Pouzite styl algoritmu Lomuto.
    Poradie usporiadania:
        Najprv (vlavo) budu prvky vacsie alebo rovne ako pivot,
        potom pivot,
        potom (vpravo) prvky mensie ako pivot.

    PARAMETRE:
        [in, out] data - pole, v ktoreho casti 'low' ... 'high'-1 bude vykonane partition
        [in] pivot     - index pivota (pred partition)
        [in] low       - index prveho prvku casti pola, v ktorej bude vykonany partition
        [in] high      - index za poslednym prvkom casti pola, v ktorej bude vykonany partition

    NAVRATOVA HODNOTA:
        Index pivota po vykonani partition.

    VSTUPNE PODMIENKY:
        'low' <= 'pivot' < 'high'
        (index pivota moze byt lubobolny v rozsahu 'low'...'high'-1, napriklad v pripade nahodneho vyberu pivota)
        'data' ukazuje na platne pole

    PRIKLADY:
        1. priklad:
            vstup:  data: {10, 20, 30, 40, 50, 60, 70, 80, 90}, pivot: 5, low: 2, high: 7
            vystup: data: {10, 20, 70, 60, 50, 30, 40, 80, 90}, return 3

        2. priklad:
            vstup:  data: {10, 20, 30, 40, 50, 60, 70, 50, 80, 90}, pivot: 4, low: 2, high: 8
            vystup: data: {10, 20, 50, 60, 70, 50, 30, 40, 80, 90}, return 5
*/
size_t partition(int *data, const size_t pivot, const size_t low, const size_t high)
{
    size_t i, tmp, insert = low, t;

    tmp = data[pivot];
    data[pivot] = data[high-1];
    data[high-1] = tmp;

    for(i = low; i < high; i++)
    {
        if (data[i] >= data[high-1]){
            t = data[insert];
            data[insert] = data[i];
            data[i] = t;
            insert++;
        }
    }

    return insert - 1;
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada cast pola 'data' (s indexami 'low' ... 'high'-1).
    Pouzite algoritmus quick sort, styl Lomuto.
    Poradie usporiadania je od najvacsieho prvku po najmensi.

    PARAMETRE:
        [in, out] data - pole, ktoreho cast funkcia usporiada
        [in] low       - index prveho prvkou casti pola, ktoru funkcia usporiada
        [in] high      - index za posledny prvok casti pola, ktoru funkcia usporiada

    VSTUPNA PODMIENKA:
        ak 'low' < 'high', tak 'data' ukazuje na platne pole

    PRIKLAD:
        data: {1, 2, 3, 4, 5, 6, 7, 8, 9}, low: 2, high: 7 -> data: {1, 2, 7, 6, 5, 4, 3, 8, 9}
*/
void quickSort(int *data, const size_t low, const size_t high)
{
    size_t pivot = getPivotIndex(data, low, high);  // Index pivota

    if (low + 1 >= high) {return;}
    if (low + 1 <= high)
    {
        pivot = partition(data, pivot, low, high);
        quickSort(data, low, pivot);
        quickSort(data, pivot + 1, high);
    }
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne funkcie a struktury

int main() {

    int pvt[] = {1, 1, 3, 2, 3};
    cout << getPivotIndex(pvt, 1, 8);
    // tu mozete doplnit testovaci kod
/*  int arr[] = {2,1,2,1};
    int arr1[] = {25,4,3,2,1};

    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(arr1) / sizeof(arr1[0]);

    printArray(arr, n);
    bubbleSort(arr, n);

    bubbleSort(arr_w, n);
    printArray(arr_w, n);

    int pvt[] = {10, 20, 2000, 1000, 30, 40, 50};
    cout << getPivotIndex(pvt, 2, 4);
    quickSort(arr1, n);
*/
    return 0;
}
