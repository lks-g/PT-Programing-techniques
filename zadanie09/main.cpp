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
     V prvych osmich prikladoch mozete pouzit iterativnu alebo rekurzivnu implementaciu. <- SPECIALNE INSTRUKCIE PRE TOTO ZADANIE
     V pripade implementacie rekurziou, moze byt hlavna cast implemetovana v pridanej rekurzivnej funkcii. <- SPECIALNE INSTRUKCIE PRE TOTO ZADANIE
(8)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo datovych typov).
     Testovaci kod ale nebude hodnoteny.
(9)  Funkcia 'main' musi byt v zdrojovom kode posledna.
*/

#include <map>
#include <set>
#include <list>
#include <queue>
#include<sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Uzol binarneho vyhladavacieho stromu
struct Node {
    int value;     // hodnota uzla
    Node *smaller; // uzol 'smaller' a jeho nasledovnici maju hodnotu mensiu ako 'value'
    Node *greater; // uzol 'greater' a jeho nasledovnici maju hodnotu vacsiu ako 'value

    explicit Node(int value = 0, Node *smaller = nullptr, Node *greater = nullptr)
            : value(value)
            , smaller(smaller)
            , greater(greater)
    {
    }
};

// Binarny vyhladavaci strom
struct BinarySearchTree {
    Node *root; // koren stromu

    explicit BinarySearchTree(Node *root = nullptr)
            : root(root)
    {
    }
};

// Vynimka oznacujuca, ze uzol so zadanou hodnotou v strome neexistuje
class ValueNotExistsException : public std::exception {
};

// Vlastna funkcia na overenie ci hodnota existuje v danom strome
bool verify(Node* node, int value) noexcept{

    if (node == nullptr){
        return false;
    }

    if (node->value == value){
        return true;
    }

    bool small = verify(node->smaller, value);
    if(small){
        return true;
    }

    bool great = verify(node->greater, value);
    return great;
}

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati najmensiu hodnotu v strome.
    V pripade neexistencie tejto hodnoty vyhodi vynimku.

    Riesenie (tejto, aj dalsich uloh) musi vyuzivat vlastnosti binarneho vyhladavacieho stromu.
    Napriklad, pri hladani minima, treba prejst len cez potrebne uzly.

    VSTUPNY PARAMETER:
        [in] tree - strom, v ktorom funkcia hlada minimum

    NAVRATOVA HODNOTA:
        najmensia hodnota v strome
0
    VYNIMKA:
        ValueNotExistsException - ak je strom prazdny
*/

int min(const BinarySearchTree *tree) {

    int min;

    if (!tree->root) {
        throw ValueNotExistsException();
    }

    Node *root = tree->root;

    while(root->smaller){
        root = root->smaller;
    }

    min = root->value;
    return min;
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati hlbku uzla s hodnotou 'value' v strome 'tree'.
    Hlbka korena je 0.
    Ak hladany uzol v strome nie je, tak funkcia vyhodi vynimku.

    VSTUPNE PARAMETRE:
        [in] tree - strom, v ktorom funkcia hlada uzol
        [in] value - hodnota hladaneho uzla

    NAVRATOVA HODNOTA:
        Hlbka uzla s hodnotou 'value'.

    VYNIMKA:
        ValueNotExistsException - ak sa uzol s hodnotou 'value' v strome nenachdza
*/

unsigned depth(const BinarySearchTree *tree, int value){

    int flag = 0;
    unsigned d = 0;

    if(!tree->root){
        throw ValueNotExistsException();
    }

    Node *root = tree->root;

    while(root){
        if(root->value == value){
            flag = 1;
            break;
        }

        if(root->value > value){
            root = root->smaller;
        }

        else if(root->value < value){
            root = root->greater;
        }
        d++;
    }

    if(flag == 1){
        return d;
    }

    else{
        throw ValueNotExistsException();
    }
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati zoznam hodnot uzlov, ktore musi prejst pri hladani uzla s hodnotou 'value'.
    Prva hodnota vystupneho zoznamu je hodnota korena, druha hodnota zoznamu je lavy alebo pravy nasledovnik korena, atd.
    Poslednou hodnotou vo vystupnom zozname je hodnota uzla, na ktorom sa hladanie zastavilo.
    Ak 'tree' obsahuje uzol s hodnotou 'value', tak poslednou hodnotou vystupeho zoznamu je 'value'.

    VSTUPNE PARAMETRE:
        [in] tree - strom, v ktorom funkcia hlada uzol s hodnotou 'value'
        [in] value - hodnota hladaneho uzla

    NAVRATOVA HODNOTA:
        Zoznam hodnot uzlov, ktorych hodnoty musela funkcia pri hladani porovnavat.
        Poradie hodnot vo vystupnom zozname musi zodpovedat poradiu prechadzania uzlov stromu.

    PRIKLADY:
        V prikladoch predpokladajme strom:
                  40
                 /  \
               20    50
              /  \    \
            10   30    60

        1. priklad
            value: 30 -> vystup: (40, 20, 30)
        2. priklad
            value: 45
            vystup: (40, 50)
*/

list<int> path(const BinarySearchTree *tree, int value) noexcept {

    Node* node = tree->root;
    list<int> val = list<int>();

    if(!tree->root){
        return val;
    }

    while(node){
        val.push_back(node->value);

        if(node->value == value){
            return val;
        }

        if(node->smaller != nullptr && node->value >= value){
            node = node->smaller;
        }

        else if(node->greater != nullptr && node->value < value){
            node = node->greater;
        }

        else{break;}
    }

    return val;
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati pocet uzlov stromu.

    VSTUPNY PARAMETER:
        [in] tree - strom, ktoreho pocet uzlov funkcia zistuje

    NAVRATOVA HODNOTA:
        pocet uzlov stromu
*/

size_t findCount(Node *node) noexcept{

    int nodeCount = 1;
    queue<Node*> Queue;

    Queue.push(node);
    while(!Queue.empty())
    {
        Node *temp = Queue.front();
        Queue.pop();

        if (temp->smaller){
            nodeCount++;
            Queue.push(temp->smaller);
        }

        if (temp->greater){
            nodeCount++;
            Queue.push(temp->greater);
        }
    }
    return nodeCount;
}

size_t count(const BinarySearchTree *tree) noexcept {

    if (!tree->root){
        return 0;
    }

    return findCount(tree->root);
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati zoznam hodnot vsetkych uzlov v strome 'tree'.
    Zoznam musi byt usporiadany od najmensieho prvku po najvacsi.

    Usporiadanie dosiahnite vhodnou postupnostou prechadzania uzlov stromu!

    VSTUPNY PARAMETER:
        [in] tree - strom, ktoreho hodnoty funkcia vrati

    NAVRATOVA HODNOTA:
        hodnoty uzlov, v poradi od najmensej po najvacsiu
*/

void allInOrder(Node *node, list<int> *val){
    if (node) {
        allInOrder(node->smaller, val);
        val->push_back(node->value);
        allInOrder(node->greater, val);
    }
}

list<int> all(const BinarySearchTree *tree) noexcept {

    Node* node = tree->root;
    list<int> val;

    if (!node){
        return val;
    }

    allInOrder(node, &val);
    return val;

}

//-------------------------------------------------------------------------------------------------
// 6. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati pocet uzlov stromu 'tree', ktorych hodnota je vacsia ako 'value'.

    VSTUPNE PARAMETRE:
        [in] tree - strom, v ktorom funkcia pocita pocet uzlov splnajich podmienku
        [in] value - hodnota, podla ktorej sa vyberaju uzly

    NAVRATOVA HODNOTA:
        pocet uzlov s hodnotou vacsou ako 'value'
*/

void countGreater(Node* node, int value, size_t &count) noexcept {

    if(node){
        countGreater(node->smaller, value, count);
        countGreater(node->greater, value, count);
        if (node->value > value){
            count++;
        }
    }
    return;
}

size_t countGreater(const BinarySearchTree *tree, int value) noexcept {

    size_t count = 0;

    if(!tree->root){
        return 0;
    }

    if(verify(tree->root, value)){
        countGreater(tree->root, value, count);
    }

    return count;
}

//-------------------------------------------------------------------------------------------------
// 7. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia odstrani vsetky uzly stromu a dealokuje ich.

    Na dealokaciu pouzite operator 'delete'!

    VSTUPNY PARAMETER:
        [in, out] tree - strom, ktoreho uzly funkcia odstrani

    VYSTUPNE PODMIENKY:
        vsetky uzly su dealokovane
        'tree->root' je nulovy smernik
*/

void clear(Node* node)
{
    if(node){
        clear(node->smaller);
        clear(node->greater);
        delete node;
    }
}

void clear(BinarySearchTree *tree) noexcept {

    if(!tree->root) return;
    clear(tree->root);
    tree->root = nullptr;
}

//-------------------------------------------------------------------------------------------------
// 8. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia hlada hodnotu 'value' vo vektore 'data'.
    Vrati pocet prvkov v 'data', ktore pri hladni porovnala s 'value'.
    Vektor 'data' obsahuje usporiadane hodnoty.
    Casova narocnost algoritmu je O(log(n)), kde n je pocet prvkov vektora.

    PARAMETRE:
        [in] data - hodnoty usporiadane od najmensieho prvku po najvacsi
        [in] value - hodnota hladana v 'data'

    NAVRATOVA HODNOTA:
        Pocet prvkov 'data', ktore funkcia pri hladani porovnala s 'value'.
        (bez ohladu na to, ci 'data' obsahuje hodnotu 'value').

    VSTUPNA PODMIENKA:
        Hodnoty v 'data' su usporiadane od najmensieho prvku po najvacsi.

    PRIKLADY:
        data = (100, 102, 104, 106, 108, 110, 112), value = 106 -> vystup: 1
        data = (100, 102, 104, 106, 108, 110, 112), value = 110 -> vystup: 2
        data = (100, 102, 104, 106, 108, 110, 112), value = 108 -> vystup: 3
        data = (100, 102, 104, 106, 108, 110), value = 104 -> vystup: 1 alebo 3
        data = (100, 102, 104, 106, 108, 110), value = 107 -> vystup: 3
        data = (100), value = 100 -> vystup: 1
        data = (100), value = 200 -> vystup: 1
        data = (), value = 100 -> vystup: 0
*/

unsigned contains(const vector<int> & data, int value) noexcept {

    int index_low = 0;
    int index_high = 0;
    vector<int> vectorData = data;


    std::vector<int>::iterator it_l = std::find(vectorData.begin(), vectorData.end(), vectorData.begin());
    std::vector<int>::iterator it_h = std::find(vectorData.begin(), vectorData.end(), vectorData.end());

    if (it_l != vectorData.cend()) {
        index_low =  std::distance(vectorData.begin(), it_l);
    }

    if (it_h != vectorData.cend()) {
        index_low =  std::distance(vectorData.begin(), it_h);
    }

    int low = index_low;
    int middle;
    int high = index_high;

    unsigned val = 0;

    if(data.empty()){
        return 0;
    }

    while(vectorData.size() > 1)
    {
        middle = low + (high - low) / 2;

        if(vectorData[middle] == value){
            return val;
        }

        if (vectorData[middle] < value) {
            low = middle;
            vectorData.front() = low;
        }

        if (vectorData[middle] > value){
            high = middle;
            vectorData.back() = high;
        }

        else break;

        val++;
    }

    return val;
}

//-------------------------------------------------------------------------------------------------
// 9. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori a vrati histogram slov v 'data' (zisti, kolko krat sa ktore slovo nachadza v 'data').

    PARAMETER:
        [in] data - vektor slov

    NAVRATOVA HODNOTA:
        histogram slov (pre kazde slovo z 'data' obsahuje pocet jeho vyskytov)

    VSTUPNE PODMIENKY:
        'data' moze obsahovat lubobolny pocet slov
        'data' moze obsahovat opakujuce sa slova
        slova mozu byt prazdne retazce

    VYSTUPNE PODMIENKY:
        Histogram obsahuje iba slova, ktore sa v 'data' nachadzaju

    PRIKLADY:
        vstup: data = ("pocitac", "lietadlo", luk", "pocitac", "pocitac", "okno", "luk")
        vystup: {"pocitac" -> 3, "lietadlo" -> 1, "luk" -> 2, "okno" -> 1}

        vstup: data = ("pocitac", "")
        vystup: {"pocitac" -> 1, "" -> 1}

        vstup: data = ()
        vystup: {}
*/

map<string, size_t> histogram(const vector<string> & data) noexcept {

    return map<string, size_t>();
}

//-------------------------------------------------------------------------------------------------
// 10. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori a vrati index slov v 'data' (pre kazde slovo mnozinu indexov jeho vyskytu).

    PARAMETER:
        [in] data - vektor slov

    NAVRATOVA HODNOTA:
        index slov (pre kazde slovo z 'data' obsahuje indexy, na ktorych sa slovo v 'data' nachadza)

    VSTUPNE PODMIENKY:
        'data' moze obsahovat lubobolny pocet slov
        'data' moze obsahovat opakujuce sa slova
        slova mozu byt prazdne retazce

    VYSTUPNE PODMIENKY:
        Index obsahuje zoznamy vyskytov len pre slova, ktore sa nachadzaju v 'data'

    PRIKLADY:
        vstup: data = ("pocitac", "lietadlo", luk", "pocitac", "pocitac", "okno", "luk")
        vystup: {"pocitac" -> {0, 3, 4}, "lietadlo" -> {1}, "luk" -> {2, 6}, "okno" -> {5}}

        vstup: data = ("pocitac", "")
        vystup: {"pocitac" -> {0}, "" -> {1}}

        vstup: data = ()
        vystup: {}
*/

map<string, set<size_t>> index(const vector<string> & data) noexcept {
    // TODO
    return map<string, set<size_t>>();
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne funkcie a struktury

// rekurzivna pomocna funkcia na pridanie uzla do stromu
Node *addNode(Node *root, const int value) {
    if (!root) return new Node{value, nullptr, nullptr};
    if (value < root->value) {
        root->smaller = addNode(root->smaller, value);
    } else {
        root->greater = addNode(root->greater, value);
    }
    return root;
}

// nerekurzivna hlavna funkcia na pridanie uzla do stromu
void addNode(BinarySearchTree *bst, const int val) {
    bst->root = addNode(bst->root, val);
}

BinarySearchTree *createBST(const initializer_list<int> &i) {
    BinarySearchTree *bst{new BinarySearchTree{nullptr}};
    for (int e: i) {
        addNode(bst, e);
    }
    return bst;
}

int main() {

    // tu mozete doplnit testovaci kod

    //vector<string> data = {"pocitac", "lietadlo", "luk", "pocitac", "pocitac", "okno", "luk"};
    //histogram(data);

    vector<int> data = {100, 102, 104, 106, 108, 110};
    cout << contains(data, 107);

    //BinarySearchTree *bst{createBST({20, 10, 70, 0, 15, 50, 80, 18, 55})};
    //BinarySearchTree *bst{createBST({20, 10, 70, 0, 15, 50, 80, 85, 18, 55, 19, 58, 17, 60})};
    //BinarySearchTree *bst{createBST({})};

    //clear(bst);
    //min(bst);
    //depth(bst, 81);

    //cout << countGreater(bst, 50);
    //path(bst, 18);
    //cout << count(bst);
    //all(bst);

    return 0;
}
