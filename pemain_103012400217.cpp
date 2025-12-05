#include "pemain.h"
#include <iostream>
using namespace std;

void createListPemain(ListPemain &L) {
    L.first = nullptr;
    L.last = nullptr;
}

adrPemain createElmPemain(string id, string nama, int score) {
    adrPemain P = new pemain;
    P->idPemain = id;
    P->nama = nama;
    P->score = score;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void insertFirstPemain(ListPemain &L, adrPemain P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastPemain(ListPemain &L, adrPemain P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void insertAfterPemain(ListPemain &L, adrPemain prec, adrPemain P) {
    if (prec == nullptr) return;

    P->next = prec->next;
    P->prev = prec;

    if (prec->next != nullptr)
        prec->next->prev = P;
    else
        L.last = P;

    prec->next = P;
}

void deleteFirstPemain(ListPemain &L, adrPemain &P) {
    if (L.first == nullptr) {
        P = nullptr;
        return;
    }

    P = L.first;

    if (L.first == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.first = P->next;
        L.first->prev = nullptr;
    }

    P->next = nullptr;
    P->prev = nullptr;
}

void deleteLastPemain(ListPemain &L, adrPemain &P) {
    if (L.first == nullptr) {
        P = nullptr;
        return;
    }

    P = L.last;

    if (L.first == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.last = P->prev;
        L.last->next = nullptr;
    }

    P->next = nullptr;
    P->prev = nullptr;
}

void deleteAfterPemain(ListPemain &L, adrPemain prec, adrPemain &P) {
    if (prec == nullptr || prec->next == nullptr) {
        P = nullptr;
        return;
    }

    P = prec->next;

    prec->next = P->next;
    if (P->next != nullptr)
        P->next->prev = prec;
    else
        L.last = prec;

    P->next = nullptr;
    P->prev = nullptr;
}

void deletePemainByID(ListPemain &L, string id) {
    adrPemain P = L.first;

    while (P != nullptr && P->idPemain != id) {
        P = P->next;
    }

    if (P == nullptr) return;

    adrPemain temp;

    if (P == L.first)
        deleteFirstPemain(L, temp);
    else if (P == L.last)
        deleteLastPemain(L, temp);
    else
        deleteAfterPemain(L, P->prev, temp);

    delete temp;
}

adrPemain findPemain(ListPemain L, string id) {
    adrPemain P = L.first;
    while (P != nullptr) {
        if (P->idPemain == id) return P;
        P = P->next;
    }
    return nullptr;
}

void printPemain(ListPemain L) {
    if (L.first == nullptr) {
        cout << "List Kosong" << endl;
        return;
    }

    adrPemain P = L.first;
    while (P != nullptr) {
        cout << "ID: " << P->idPemain << endl;
        cout << "Nama: " << P->nama << endl;
        cout << "Score: " << P->score << endl;
        cout << "-----" << endl;
        P = P->next;
    }
}

