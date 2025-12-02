#include "pemain.h"
#include <iostream>
using namespace std;

void createListPemain_103012400217(ListPemain &L) {
    L.first = nullptr;
}

adrPemain createElmPemain_103012400217(string id, string nama, int score) {
    adrPemain P = new pemain;
    P->idPemain = id;
    P->nama = nama;
    P->score = score;
    P->next = nullptr;
    return P;
}

void insertFirstPemain_103012400217(ListPemain &L, adrPemain P) {
    P->next = L.first;
    L.first = P;
}

void insertLastPemain_103012400217(ListPemain &L, adrPemain P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        adrPemain Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteFirstPemain_103012400217(ListPemain &L) {
    if (L.first != nullptr) {
        adrPemain P = L.first;
        L.first = P->next;
        delete P;
    }
}

void deleteLastPemain_103012400217(ListPemain &L) {
    if (L.first != nullptr) {
        if (L.first->next == nullptr) {
            delete L.first;
            L.first = nullptr;
        } else {
            adrPemain Q = L.first;
            while (Q->next->next != nullptr) {
                Q = Q->next;
            }
            delete Q->next;
            Q->next = nullptr;
        }
    }
}

void deletePemainByID_103012400217(ListPemain &L, string id) {
    if (L.first == nullptr) return;

    if (L.first->idPemain == id) {
        deleteFirstPemain_103012400217(L);
        return;
    }

    adrPemain Q = L.first;
    while (Q->next != nullptr && Q->next->idPemain != id) {
        Q = Q->next;
    }

    if (Q->next != nullptr) {
        adrPemain P = Q->next;
        Q->next = P->next;
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
        Q = Q->next;
    }
}
