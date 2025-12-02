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
};

struct ListPemain {
    adrPemain first;
};

// FUNCTION PROTOTYPES
void createListPemain_103012400217(ListPemain &L);
adrPemain createElmPemain_103012400217(string id, string nama, int score);
void insertFirstPemain_103012400217(ListPemain &L, adrPemain P);
void insertLastPemain_103012400217(ListPemain &L, adrPemain P);
void deleteFirstPemain_103012400217(ListPemain &L);
void deleteLastPemain_103012400217(ListPemain &L);
void deletePemainByID_103012400217(ListPemain &L, string id);
adrPemain findPemain_103012400217(ListPemain L, string id);
void printPemain_103012400217(ListPemain L);

#endif
