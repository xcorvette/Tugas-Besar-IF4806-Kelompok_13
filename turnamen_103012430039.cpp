#include <iostream>
#include "turnamen.h"

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
        cout<< "List Kosong"<<endl;
    }else{
        p->next = prec->next;
        prec->next = p;
    }
}
adrTurnamen searchTurnamenByNama(ListTurnamen L, string namaTurnamen){
    adrTurnamen p = L.first;
    while(p!=nullptr){
        if (p->info.namaTurnamen== namaTurnamen){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}
adrTurnamen searchTurnamenByKategori(ListTurnamen L, string kategori){
    adrTurnamen p = L.first;
    while(p!=nullptr){
        if (p->info.kategori== kategori){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

adrTurnamen searchTurnamenByTahun(ListTurnamen L, int tahun){}
void insertTurnamenByTahun(ListTurnamen &L, adrTurnamen p){}
void deleteTurnamenByNama(ListTurnamen &L, string namaTurnamen){}

int hitungJumlahTurnamen(ListTurnamen L){}
int hitungTurnamenByTahun(ListTurnamen L, int tahun){}

void displayTurnamen(ListTurnamen L){}
