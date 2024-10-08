#include <iostream>
#include "league.h"
using namespace std;

void createList(List &L) {
    first(L) = NULL;
}

address allocate(infotype x) {
    address p = new elmlist;
    info(p) = x;
    next(p) = NULL;
    return p;
}

void insertFirst(List &L, address P){
    if (first(L) == NULL){
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLast(List &L, address P) {
    address Q;

    if (first(L) == NULL) {
        insertFirst(L, P);
    } else {
        Q = first(L);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void insertAfter(List &L, address PREC, address P) {
    if (next(PREC) == NULL) {
        insertLast(L, P);
    } else {
        next(P) = next(PREC);
        next(PREC) = P;
    }
}

void deleteFirst(List &L, address P){
    if (first(L) == NULL) {
        P = NULL;
    } else {
        P = first(L);
        first(L) = next(P);
        P = NULL;
    }
}

void deleteLast(List &L, address P){
    address Q;

    if (first(L) == NULL) {
        P = NULL;
    } else {
        Q = first(L);
        while (next(next(Q)) != NULL) {
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = NULL;
    }
}

void deleteAfter(List &L, address PREC, address P){
    if (next(PREC) == NULL) {
        deleteLast(L, P);
    } else {
        P = next(PREC);
        next(PREC) = next(P);
        next(P) = NULL;
    }
}

void sortBy(List &L){
    address P, Q, SL;

    if (next(first(L))!= NULL) {
        P = first(L);
        SL = NULL;
        while (P != NULL) {
            first(L) = next(P);
            if (SL == NULL || info(SL).tanggal > info(P).tanggal) {
                next(P) = SL;
                SL = P;
            } else {
                Q = SL;
                while (next(Q) != NULL && info(next(Q)).tanggal < info(P).tanggal) {
                    Q = next(Q);
                }
                next(P) = next(Q);
                next(Q) = P;
            }
            P = first(L);
        }
        first(L) = SL;
    }
}

void printInfo(List L){
    if (first(L) == NULL){
        cout << "LIST KOSONG" << endl;
    } else {
        address Q = first(L);
        while (Q != NULL) {
            cout << info(Q).kandang << " " << info(Q).musuh << " " << info(Q).tanggal << endl;
            Q = next(Q);
        }
        cout << endl;
    }
}

address searchByPosition(List &L, int position) {
    address P = first(L);
    int count = 1;

    while (P != NULL && count < position) {
        P = next(P);
        count++;
    }

    return P;
}
