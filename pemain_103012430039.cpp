#include <iostream>
#include "pemain.h"

using namespace std;

void insertAfterPemain(ListPemain &L, adrPemain prec, adrPemain P){
    if (prec == nullptr || L.first == nullptr){
        cout << "List Kosong!" <<endl;
    }else{
        P->next = prec->next;
        P->prev = prec;
        prec->next->prev = P;
        prec->next =P;
    }
}
void deleteAfterPemain(ListPemain &L, adrPemain prec, adrPemain &P){
    if (prec == nullptr || prec->next == nullptr){
        P = nullptr;
    }else{
        P->next = prec->next;
        P->prev = prec;
        prec->next->prev = P;
        prec->next =P;
    }
}
