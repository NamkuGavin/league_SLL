#ifndef LEAGUE_H_INCLUDED
#define LEAGUE_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
using namespace std;
typedef struct data infotype;
typedef struct elmlist *address;

struct data {
    string kandang, musuh;
    int tanggal;
};

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &GAA);
address allocate(infotype x);

void insertFirst(List &GAA, address P);
void insertLast(List &GAA, address P);
void insertAfter(List &GAA, address PREC ,address P);

void deleteFirst(List &GAA, address P);
void deleteLast(List &GAA, address P);
void deleteAfter(List &GAA, address PREC ,address P);

void sortBy(List &GAA);
void printInfo(List GAA);
address searchByPosition(List &L, int position);



#endif // LEAGUE_H_INCLUDED
