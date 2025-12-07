#include <iostream>
#include "header.h"

using namespace std;

bool isEmptyPemain(adrTurnamen T){
  return (T->firstPemain == nullptr);
}
adrPemain createElmPemain(string id, string nama, int score){
    adrPemain P = new pemain;
    P->idPemain = id;
    P->nama = nama;
    P->score = score;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}
void insertFirstPemain(adrTurnamen &T, adrPemain P){
     if (isEmptyPemain(T)){
        T->firstPemain = P;
        T->lastPemain = P;
    } else {
        P->next = T->firstPemain;
        T->firstPemain->prev = P;
        T->firstPemain = P;
    }
}
void insertLastPemain(adrTurnamen &T, adrPemain P){
    if (T == nullptr){
        cout << "Turnamen null. InsertLastPemain dibatalkan.\n";
    } else {
        if (isEmptyPemain(T)){
            T->firstPemain = P;
            T->lastPemain = P;
        } else {
            T->lastPemain->next = P;
            P->prev = T->lastPemain;
            T->lastPemain = P;
        }
    }
}
void insertAfterPemain(adrTurnamen &T, adrPemain prec, adrPemain P){
     if (isEmptyPemain(T) || prec == nullptr){
        cout << "List pemain kosong atau prec tidak valid!\n";
    } else {
        P->next = prec->next;
        P->prev = prec;

        if (prec->next != nullptr){
            prec->next->prev = P;
        }
        prec->next = P;

        if (prec == T->lastPemain){
            T->lastPemain = P;
        }
    }
}
adrPemain findPemain(adrTurnamen &T, string id){
    if (isEmptyPemain(T)) return nullptr;

    adrPemain P = T->firstPemain;
    while (P != nullptr){
        if (P->idPemain == id){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void deletePemainByID(adrTurnamen &T, string id){
     if (isEmptyPemain(T)){
        cout << "Tidak ada pemain.\n";
    }
    else {
        adrPemain P = findPemain(T, id);
        adrPemain throwaway;
        if (P == nullptr){
            cout << "ID tidak ditemukan.\n";
        }
        else if (P == T->firstPemain){
            deleteFirstPemain(T, throwaway);
        }
        else if (P == T->lastPemain){
            deleteLastPemain(T, throwaway);
        }
        else {
            deleteAfterPemain(T, P->prev, throwaway);
        }
    }
}
void printPemain(adrTurnamen T){
   if (isEmptyPemain(T)){
        cout << "Tidak ada pemain.\n";
    }
    else {
        cout << "\n--- Daftar Pemain ---\n";
        adrPemain P = T->firstPemain;

        while (P != nullptr){
            cout << "ID     : " << P->idPemain << endl;
            cout << "Nama   : " << P->nama << endl;
            cout << "Score  : " << P->score << endl;
            cout << "--------------------------\n";
            P = P->next;
        }
    }
}
