#include <iostream>
#include "header.h"

using namespace std;
void deleteAllPemain(adrTurnamen p){

    adrPemain q = p->firstPemain;
    while (q!= nullptr){
        q = q->next;
    }
    p->firstPemain = nullptr;
}
void deleteFirstTurnamen(ListTurnamen &L, adrTurnamen &p){
    if(isEmptyTurnamen(L)){
        p = nullptr;
    }else if (L.first->next == nullptr){
        p = L.first;
        deleteAllPemain(p);
        L.first = nullptr;
    }else{
        p = L.first;
        deleteAllPemain(p);
        L.first = p->next;
        p->next = nullptr;
    }
}
void deleteLastTurnamen(ListTurnamen &L, adrTurnamen &p){
    if(isEmptyTurnamen(L)){
        p = nullptr;
    }else if (L.first->next == nullptr){
        p = L.first;
        deleteAllPemain(p);
        L.first = nullptr;
    }else{
        adrTurnamen q = L.first;
        while (q->next->next != nullptr){
            q = q->next;
        }
        p = q->next;
        deleteAllPemain(p);
        q->next = nullptr;
    }
}
void deleteAfterTurnamen(ListTurnamen &L, adrTurnamen prec, adrTurnamen &p){
    if (prec == nullptr || prec->next == nullptr){
        p = nullptr;
    }else{
        p = prec->next;
        deleteAllPemain(p);
        prec->next = p->next;
        p->next = nullptr;
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
adrTurnamen searchTurnamenByTahun(ListTurnamen L, int tahun){
    adrTurnamen p = L.first;
    while (p!= nullptr){
        if(p->info.tahun == tahun){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}
int hitungPemainPadaTurnamen(adrTurnamen p){
    int jumlah = 0;
    adrPemain q = p->firstPemain;
    while (q!= nullptr){
        jumlah++;
        q =q->next;
    }
    return jumlah;
}
void displayTurnamen(ListTurnamen L){
    if (isEmptyTurnamen(L)){
        cout << "Belum ada turnamen.\n";
    } else {
        adrTurnamen p = L.first;
        cout << "\n=== Daftar Turnamen ===\n";
        while (p != nullptr){
            cout << "Nama        : " << p->info.namaTurnamen << "\n";
            cout << "Lokasi      : " << p->info.lokasi << "\n";
            cout << "Tanggal Mulai: " << p->info.tanggalMulai << "\n";
            cout << "Tanggal Selesai: " << p->info.tanggalSelesai << "\n";
            cout << "Tahun       : " << p->info.tahun << "\n";
            cout << "Kategori    : " << p->info.kategori << "\n";
            cout << "-----------------------------\n";
            p = p->next;
        }
    }
}
