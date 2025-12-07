
#define TURNAMEN_H_INCLUDED

#include <string>
#include "pemain.h"

using namespace std;

typedef struct elmTurnamen *adrTurnamen;
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
};
struct ListTurnamen{
    adrTurnamen first;
};
void createListTurnamen( ListTurnamen &L);
bool isEmptyTurnamen( ListTurnamen L);
adrTurnamen createElemenTurnamen(Turnamen x);
void insertFirstTurnamen(ListTurnamen &L, adrTurnamen p);
void insertLastTurnamen(ListTurnamen &L, adrTurnamen p);
void insertAfterTurnamen(ListTurnamen &L,adrTurnamen prec, adrTurnamen p);
void deleteFirstTurnamen(ListTurnamen &L, adrTurnamen &p);
void deleteLastTurnamen(ListTurnamen &L, adrTurnamen &p);
void deleteAfterTurnamen(ListTurnamen &L, adrTurnamen prec, adrTurnamen &p);

adrTurnamen searchTurnamenByNama(ListTurnamen L, string namaTurnamen);
adrTurnamen searchTurnamenByKategori(ListTurnamen L, string kategori);
adrTurnamen searchTurnamenByTahun(ListTurnamen L, int tahun);

void insertTurnamenByTahun(ListTurnamen &L, adrTurnamen p);
void deleteTurnamenByNama(ListTurnamen &L, string namaTurnamen);

int hitungJumlahTurnamen(ListTurnamen L);
int hitungTurnamenByTahun(ListTurnamen L, int tahun);

void displayTurnamen(ListTurnamen L);
