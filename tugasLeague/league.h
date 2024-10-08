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

void createList(List &L);
address allocate(infotype x);

void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address PREC ,address P);

void deleteFirst(List &L, address P);
void deleteLast(List &L, address P);
void deleteAfter(List &L, address PREC ,address P);

void sortBy(List &L);
void printInfo(List L);
address searchByPosition(List &L, int position);



#endif // LEAGUE_H_INCLUDED
