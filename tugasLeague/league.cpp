#include <iostream>
#include "league.h"
using namespace std;

void createList(List &GAA) {
    first(GAA) = NULL;
}

address allocate(infotype x) {
    address p = new elmlist;
    info(p) = x;
    next(p) = NULL;
    return p;
}

void insertFirst(List &GAA, address P){
    if (first(GAA) == NULL){
        first(GAA) = P;
    } else {
        next(P) = first(GAA);
        first(GAA) = P;
    }
}

void insertLast(List &GAA, address P) {
    address Q;

    if (first(GAA) == NULL) {
        insertFirst(GAA, P);
    } else {
        Q = first(GAA);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void insertAfter(List &GAA, address PREC, address P) {
    if (next(PREC) == NULL) {
        insertLast(GAA, P);
    } else {
        next(P) = next(PREC);
        next(PREC) = P;
    }
}

void deleteFirst(List &GAA, address P){
    if (first(GAA) == NULL) {
        P = NULL;
    } else {
        P = first(GAA);
        first(GAA) = next(P);
        P = NULL;
    }
}

void deleteLast(List &GAA, address P){
    address Q;

    if (first(GAA) == NULL) {
        P = NULL;
    } else {
        Q = first(GAA);
        while (next(next(Q)) != NULL) {
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = NULL;
    }
}

void deleteAfter(List &GAA, address PREC, address P){
    if (next(PREC) == NULL) {
        deleteLast(GAA, P);
    } else {
        P = next(PREC);
        next(PREC) = next(P);
        next(P) = NULL;
    }
}

void sortBy(List &GAA){
    address P, Q, SL;

    if (next(first(GAA))!= NULL) {
        P = first(GAA);
        SL = NULL;
        while (P != NULL) {
            first(GAA) = next(P);
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
            P = first(GAA);
        }
        first(GAA) = SL;
    }
}

void printInfo(List GAA){
    if (first(GAA) == NULL){
        cout << "LIST KOSONG" << endl;
    } else {
        address Q = first(GAA);
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
