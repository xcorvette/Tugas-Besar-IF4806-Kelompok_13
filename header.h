#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <string>
using namespace std;

typedef struct elmTurnamen *adrTurnamen;
typedef struct pemain *adrPemain;
//deklarasi turnamen
struct Turnamen{
    string namaTurnamen;
    string lokasi;
    string tanggalMulai;
    string tanggalSelesai;
    int tahun;
    string kategori;
};
struct elmTurnamen{
    Turnamen info;
    adrTurnamen next;
    adrPemain firstPemain; //pointer ke pemain (child)
    adrPemain lastPemain; //pointer ke pemain (child)
};
struct ListTurnamen{
    adrTurnamen first;
};
// deklarasi Pemain
struct pemain {
    string idPemain;
    string nama;
    int score;
    adrPemain next;
    adrPemain prev;
};

//FUNGSI DASAR TURNAMEN
void createListTurnamen( ListTurnamen &L);
bool isEmptyTurnamen( ListTurnamen L);
adrTurnamen createElemenTurnamen(Turnamen x);
void insertFirstTurnamen(ListTurnamen &L, adrTurnamen p);
void insertLastTurnamen(ListTurnamen &L, adrTurnamen p);
void insertAfterTurnamen(ListTurnamen &L,adrTurnamen prec, adrTurnamen p);
void deleteFirstTurnamen(ListTurnamen &L, adrTurnamen &p);
void deleteLastTurnamen(ListTurnamen &L, adrTurnamen &p);
void deleteAfterTurnamen(ListTurnamen &L, adrTurnamen prec, adrTurnamen &p);
void displayTurnamen(ListTurnamen L);

//FUNGSI DASAR PEMAIN
bool isEmptyPemain(adrTurnamen T);
adrPemain createElmPemain(string id, string nama, int score);
void insertFirstPemain(adrTurnamen &T, adrPemain P);
void insertLastPemain(adrTurnamen &T, adrPemain P);
void insertAfterPemain(adrTurnamen &T, adrPemain prec, adrPemain P);
void deleteFirstPemain(adrTurnamen &T, adrPemain &P);
void deleteLastPemain(adrTurnamen &T, adrPemain &P);
void deleteAfterPemain(adrTurnamen &T, adrPemain prec, adrPemain &P);
adrPemain findPemain(adrTurnamen &T, string id);

//FUNGSI KONDISI
adrTurnamen searchTurnamenByNama(ListTurnamen L, string namaTurnamen);
adrTurnamen searchTurnamenByTahun(ListTurnamen L, int tahun);
void deleteAllPemain(adrTurnamen p);
int hitungPemainPadaTurnamen(adrTurnamen p);
void deletePemainByID(adrTurnamen &T, string id);
void printPemain(adrTurnamen T);
bool sudahIkutTahunIni(ListTurnamen L, string idPemain, int tahun);
#endif
