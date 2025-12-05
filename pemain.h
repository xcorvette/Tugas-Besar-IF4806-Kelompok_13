#ifndef PEMAIN_H_INCLUDED
#define PEMAIN_H_INCLUDED

#include <string>
using namespace std;

typedef struct pemain *adrPemain;

struct pemain {
    string idPemain;
    string nama;
    int score;
    adrPemain next;
    adrPemain prev;
};

struct ListPemain {
    adrPemain first;
    adrPemain last;
};

void createListPemain(ListPemain &L);
adrPemain createElmPemain(string id, string nama, int score);

void insertFirstPemain(ListPemain &L, adrPemain P);
void insertLastPemain(ListPemain &L, adrPemain P);
void insertAfterPemain(ListPemain &L, adrPemain prec, adrPemain P);

void deleteFirstPemain(ListPemain &L, adrPemain &P);
void deleteLastPemain(ListPemain &L, adrPemain &P);
void deleteAfterPemain(ListPemain &L, adrPemain prec, adrPemain &P);

void deletePemainByID(ListPemain &L, string id);
adrPemain findPemain(ListPemain L, string id);
void printPemain(ListPemain L);

#endif
