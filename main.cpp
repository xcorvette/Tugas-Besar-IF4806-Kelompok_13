
#include <iostream>
#include "header.h"
#include "menu.h"

using namespace std;


void insertDummyData(ListTurnamen &L) {
    // TURNAMEN 1
    Turnamen t1;
    t1.namaTurnamen = "Indonesia Open";
    t1.lokasi = "Jakarta";
    t1.tanggalMulai = "01-06-2024";
    t1.tanggalSelesai = "07-06-2024";
    t1.tahun = 2024;
    t1.kategori = "Ganda Campur";

    adrTurnamen T1 = createElemenTurnamen(t1);
    insertLastTurnamen(L, T1);

    insertLastPemain(T1, createElmPemain("P01", "Ginting", 85));
    insertLastPemain(T1, createElmPemain("P02", "Jojo", 90));
    insertLastPemain(T1, createElmPemain("P03", "Fajar", 88));

    //  TURNAMEN 2
    Turnamen t2;
    t2.namaTurnamen = "All England";
    t2.lokasi = "Birmingham";
    t2.tanggalMulai = "10-03-2024";
    t2.tanggalSelesai = "17-03-2024";
    t2.tahun = 2024;
    t2.kategori = "Ganda Putra";

    adrTurnamen T2 = createElemenTurnamen(t2);
    insertLastTurnamen(L, T2);

    insertLastPemain(T2, createElmPemain("P04", "Axelsen", 92));
    insertLastPemain(T2, createElmPemain("P05", "LeeZiiJia", 87));
    insertLastPemain(T2, createElmPemain("P06", "Momota", 89));

    //  TURNAMEN 3
    Turnamen t3;
    t3.namaTurnamen = "Japan Open";
    t3.lokasi = "Tokyo";
    t3.tanggalMulai = "20-08-2024";
    t3.tanggalSelesai = "26-08-2024";
    t3.tahun = 2024;
    t3.kategori = "Ganda Putri";

    adrTurnamen T3 = createElemenTurnamen(t3);
    insertLastTurnamen(L, T3);

    insertLastPemain(T3, createElmPemain("P07", "ShiYuQi", 91));
    insertLastPemain(T3, createElmPemain("P08", "Kunlavut", 86));
    insertLastPemain(T3, createElmPemain("P09", "Christie", 88));
}

int main() {
    ListTurnamen L;
    int pilih = 1;
    createListTurnamen(L);
    insertDummyData(L);
    while (pilih != 0) {
        cout << "=================================================\n";
        cout << "|  SISTEM MANAJEMEN TURNAMEN BADMINTON TAHUNAN  |\n";
        cout << "=================================================\n";
        cout << "| 1. Admin                                      |\n";
        cout << "| 2. User                                       |\n";
        cout << "| 0. Keluar                                     |\n";
        cout << "=================================================\n";
        cout << "Masukkan Pilihan Anda: ";
        cin >> pilih;

        if (pilih == 1) {
            menuAdmin(L);
        }else if (pilih == 2) {
            menuUser(L);
        }else if (pilih == 0) {
            cout << "Keluar dari program...\n";
        }else {
            cout << "Pilihan tidak valid!\n";
        }

        cout << endl;
    }
    cout << "Program selesai.\n";
    return 0;

}
