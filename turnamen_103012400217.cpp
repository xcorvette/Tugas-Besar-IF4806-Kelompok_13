#include <iostream>
#include "header.h"

using namespace std;

void createListTurnamen( ListTurnamen &L){
    L.first = nullptr;
}
bool isEmptyTurnamen( ListTurnamen L){
    return L.first==nullptr;
}
adrTurnamen createElemenTurnamen(Turnamen x){
    adrTurnamen p = new elmTurnamen;

    p->info.namaTurnamen = x.namaTurnamen;
    p->info.lokasi = x.lokasi;
    p->info.tanggalMulai = x.tanggalMulai;
    p->info.tanggalSelesai = x.tanggalSelesai;
    p->info.tahun = x.tahun;
    p->info.kategori = x.kategori;
    p->next = nullptr;
    p->firstPemain = nullptr;

    return p;
}
void insertFirstTurnamen(ListTurnamen &L, adrTurnamen p){
    if (isEmptyTurnamen(L)){
        L.first=p;
    }else{
        p->next = L.first;
        L.first = p;
    }
}
void insertLastTurnamen(ListTurnamen &L, adrTurnamen p){
    if (isEmptyTurnamen(L)){
        L.first = p;
    }else{
        adrTurnamen q = L.first;
        while(q->next!= nullptr){
            q = q->next;
        }
        q->next = p;
    }
}
void insertAfterTurnamen(ListTurnamen &L,adrTurnamen prec, adrTurnamen p){
    if (prec == nullptr){
        cout<< "List Turnamen Kosong"<<endl;
    }else{
        p->next = prec->next;
        prec->next = p;
    }
}
