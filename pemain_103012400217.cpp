#include "pemain.h"
#include <iostream>
using namespace std;

void createListPemain_103012400217(ListPemain &L) {
    L.first = nullptr;
    L.last = nullptr;
}

adrPemain createElmPemain_103012400217(string id, string nama, int score) {
    adrPemain P = new pemain;
    P->idPemain = id;
    P->nama = nama;
    P->score = score;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void insertFirstPemain_103012400217(ListPemain &L, adrPemain P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastPemain_103012400217(ListPemain &L, adrPemain P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void deleteFirstPemain_103012400217(ListPemain &L) {
    if (L.first == nullptr) return;

    adrPemain P = L.first;
    if (L.first == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.first = P->next;
        L.first->prev = nullptr;
    }
    delete P;
}

void deleteLastPemain_103012400217(ListPemain &L) {
    if (L.first == nullptr) return;

    adrPemain P = L.last;
    if (L.first == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.last = P->prev;
        L.last->next = nullptr;
    }
    delete P;
}

void deletePemainByID_103012400217(ListPemain &L, string id) {
    adrPemain P = findPemain_103012400217(L, id);
    if (P == nullptr) return;

    if (P == L.first) {
        deleteFirstPemain_103012400217(L);
    }
    else if (P == L.last) {
        deleteLastPemain_103012400217(L);
    }
    else {
        P->prev->next = P->next;
        P->next->prev = P->prev;
        delete P;
    }
}

adrPemain findPemain_103012400217(ListPemain L, string id) {
    adrPemain Q = L.first;
    while (Q != nullptr) {
        if (Q->idPemain == id) return Q;
        Q = Q->next;
    }
    return nullptr;
}

void printPemain_103012400217(ListPemain L) {
    if (L.first == nullptr) {
        cout << "List Kosong" << endl;
        return;
    }
    adrPemain Q = L.first;
    while (Q != nullptr) {
        cout << "ID: " << Q->idPemain << endl;
        cout << "Nama: " << Q->nama << endl;
        cout << "Score: " << Q->score << endl;
        cout << "------------------" << endl;
        Q = Q->next;
    }
}
