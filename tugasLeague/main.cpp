#include <iostream>
#include "league.h"

using namespace std;

int main() {
    List GAA;
    infotype x;
    address p, searching;
    string kandang, musuh;
    int tanggal, cariPosisi;

    createList(GAA);
    cout << "data ke 1: ";
    cin >> kandang >> musuh >> tanggal;
    x.kandang = kandang;
    x.musuh = musuh;
    x.tanggal = tanggal;
    p = allocate(x);
    insertFirst(GAA, p);

    cout << "data ke 2: ";
    cin >> kandang >> musuh >> tanggal;
    x.kandang = kandang;
    x.musuh = musuh;
    x.tanggal = tanggal;
    p = allocate(x);
    insertLast(GAA, p);

    cout << "data ke 3: ";
    cin >> kandang >> musuh >> tanggal;
    x.kandang = kandang;
    x.musuh = musuh;
    x.tanggal = tanggal;
    p = allocate(x);
    insertFirst(GAA, p);

    cout << "data ke 4: ";
    cin >> kandang >> musuh >> tanggal;
    x.kandang = kandang;
    x.musuh = musuh;
    x.tanggal = tanggal;
    p = allocate(x);
    insertLast(GAA, p);

    cout << "data ke 5 taruh di setelah data ke-: ";
    cin >> cariPosisi;
    searching = searchByPosition(GAA, cariPosisi);
    cout << "data ke 5: ";
    cin >> kandang >> musuh >> tanggal;
    x.kandang = kandang;
    x.musuh = musuh;
    x.tanggal = tanggal;
    p = allocate(x);
    insertAfter(GAA, searching, p);

    cout << "data ke 6 taruh di setelah data ke-: ";
    cin >> cariPosisi;
    searching = searchByPosition(GAA, cariPosisi);
    cout << "data ke 6: ";
    cin >> kandang >> musuh >> tanggal;
    x.kandang = kandang;
    x.musuh = musuh;
    x.tanggal = tanggal;
    p = allocate(x);
    insertAfter(GAA, searching, p);
    printInfo(GAA);

    cout << "Menghapus setelah data ke-: ";
    cin >> cariPosisi;
    searching = searchByPosition(GAA, cariPosisi);
    deleteAfter(GAA, searching, p);

    cout << "Menghapus setelah data ke-: ";
    cin >> cariPosisi;
    searching = searchByPosition(GAA, cariPosisi);
    if (next(searching) == NULL) {
        deleteLast(GAA, p);
    } else if (cariPosisi == 1) {
        deleteFirst(GAA, p);
    } else {
        deleteAfter(GAA, searching, p);
    }

    sortBy(GAA);
    printInfo(GAA);
    return 0;
}
