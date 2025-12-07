#include <iostream>
#include "header.h"

using namespace std;
void deleteFirstPemain(adrTurnamen &T, adrPemain &P){
    if (isEmptyPemain(T)){
         P = nullptr;
    }
    else if (T->firstPemain == T->lastPemain){
        P = T->firstPemain;
        T->firstPemain = nullptr;
        T->lastPemain = nullptr;
    }
    else {
        P = T->firstPemain;
        T->firstPemain = P->next;
        T->firstPemain->prev = nullptr;
        P->next = nullptr;
        P->prev = nullptr;
    }
}
void deleteLastPemain(adrTurnamen &T, adrPemain &P){
    if (isEmptyPemain(T)){
         P = nullptr;
    }
    else if (T->firstPemain == T->lastPemain){
        P = T->firstPemain;
        T->firstPemain = nullptr;
        T->lastPemain = nullptr;
    }
    else {
        P = T->lastPemain;
        T->lastPemain = P->prev;
        T->lastPemain->next = nullptr;
        P->prev = nullptr;
        P->next = nullptr;
    }
}
void deleteAfterPemain(adrTurnamen &T, adrPemain prec, adrPemain &P){
    if (isEmptyPemain(T) || prec == nullptr || prec->next == nullptr){
        P = nullptr;
    }
    else if (prec->next == T->lastPemain){
        P = T->lastPemain;
        deleteLastPemain(T, P);
    }
    else {
        P = prec->next;
        prec->next = P->next;
        P->next->prev = prec;
        P->next = nullptr;
        P->prev = nullptr;
    }
}

bool sudahIkutTahunIni(ListTurnamen L, string idPemain, int tahun){
    adrTurnamen t = L.first;
    while (t != nullptr){
        if (t->info.tahun == tahun){
            adrPemain q = t->firstPemain;
            while (q != nullptr){
                if (q->idPemain == idPemain){
                    return true;
                }
                q = q->next;
            }
        }
        t = t->next;
    }
    return false;
}

