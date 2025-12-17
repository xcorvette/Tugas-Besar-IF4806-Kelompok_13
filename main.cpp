#include <iostream>
#include "header.h"
#include "menu.h"

using namespace std;

int main() {
    ListTurnamen L;
    int pilih = 1;
    createListTurnamen(L);

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
        }
        else if (pilih == 2) {
            menuUser(L);
        }
        else if (pilih == 0) {
            cout << "Keluar dari program...\n";
        }
        else {
            cout << "Pilihan tidak valid!\n";
        }

        cout << endl;
    }

    cout << "Program selesai.\n";
    return 0;
}
