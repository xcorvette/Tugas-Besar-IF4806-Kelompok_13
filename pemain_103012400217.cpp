#include "pemain.h"
#include <iostream>
using namespace std;

void createListPemain(ListPemain &L) {
    L.first = nullptr;
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
    if (L.first == nullptr){
        L.first = P;
    }else{
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}
void insertLastPemain(ListPemain &L, adrPemain P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        adrPemain Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
        P->prev = Q;
    }
}
void deleteFirstPemain(ListPemain &L, adrPemain &P) {
    if (L.first == nullptr) { // jika list kosong
        P = nullptr;
        cout<<"List Kosong"<<endl;
    } else if (L.first->next == nullptr){
        // jika ada 1 elemen
        P = L.first;
        L.first = nullptr;
        P->next = nullptr;
        P->prev = nullptr;
    } else { // jika lebih dari 1 elemen
        P = L.first;
        L.first = P->next;
        L.first->prev = nullptr;
        P->next = nullptr;
        P->prev = nullptr;
    }
}
void deleteLastPemain(ListPemain &L, adrPemain &P) {
    if(L.first == nullptr) { // jika list kosong
        P = nullptr;
        cout<<"List Kosong"<<endl;
    } else if (L.first->next == nullptr){
        // jika ada 1 elemen
        P = L.first;
        L.first = nullptr;
        P->next = nullptr;
        P->prev = nullptr;
    } else { // jika lebih dari 1 elemen
        adrPemain Q = L.first;
        while (Q->next->next != nullptr) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
        P->prev = nullptr;
    }
}
void deletePemainByID(ListPemain &L, string id) {
    if (L.first == nullptr){
        return;
    }
    adrPemain P = nullptr;
    if (L.first->idPemain == id) {
        deleteFirstPemain(L, P);
        if (P != nullptr) {
            delete P;
        }
        return;
    }
    adrPemain Q = L.first;
    while (Q->next != nullptr && Q->next->idPemain != id) {
        Q = Q->next;
    }
    if (Q->next != nullptr) {
        adrPemain R = Q->next;
        Q->next = R->next;
        if (R->next != nullptr) {
            R->next->prev = Q;
        }
        R->next = nullptr;
        R->prev = nullptr;
        delete R;
    }
}
adrPemain findPemain(ListPemain L, string id) {
    adrPemain Q = L.first;
    while (Q != nullptr) {
        if (Q->idPemain == id) return Q;
        Q = Q->next;
    }
    return nullptr;
}
void printPemain(ListPemain L) {
    if (L.first == nullptr) {
        cout << "List Kosong" << endl;
        return;
    }
    adrPemain Q = L.first;
    cout << "--- Daftar Pemain ---" << endl;
    while (Q != nullptr) {
        cout << "ID: " << Q->idPemain << endl;
        cout << "Nama: " << Q->nama << endl;
        cout << "Score: " << Q->score << endl;
        Q = Q->next;
    }
}
