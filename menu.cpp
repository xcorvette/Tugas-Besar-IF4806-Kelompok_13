#include <iostream>
#include "menu.h"

using namespace std;

void menuAdmin(ListTurnamen &L){
    int pilih = 1;
    while (pilih != 0){
        cout <<"============================================"<<endl;
        cout <<"|               MENU ADMIN                 |"<<endl;
        cout <<"============================================"<<endl;
        cout <<"|1. Menu Turnamen                          |"<<endl;
        cout <<"|2. Menu Pemain                            |"<<endl;
        cout <<"|0. Kembali ke main menu                   |"<<endl;
        cout <<"============================================"<<endl;
        cout << "Masukkan Pilihan Anda: ";
        cin >> pilih;
        if (pilih == 1){
            menuTurnamen(L);
        }else if (pilih == 2){
            menuPemain(L);
        }else if (pilih == 0){
            cout<<"Kembali ke main menu ";
        }else {
            cout << "pilihan tidak valid ";
        }
        cout<<endl;
    }
}
void menuTurnamen(ListTurnamen &L){
    int pilih = 1;
    Turnamen x;
    adrTurnamen p, prec;
    string nama;
    int tahun;
    while (pilih != 0) {
        cout << "============================================"<<endl;
        cout << "|              MENU TURNAMEN               |"<<endl;
        cout << "============================================"<<endl;
        cout << "| 1. Insert First Turnamen                 |"<<endl;
        cout << "| 2. Insert Last Turnamen                  |"<<endl;
        cout << "| 3. Insert After Turnamen                 |"<<endl;
        cout << "| 4. Delete First Turnamen                 |"<<endl;
        cout << "| 5. Delete Last Turnamen                  |"<<endl;
        cout << "| 6. Delete After Turnamen                 |"<<endl;
        cout << "| 7. Search Turnamen                       |"<<endl;
        cout << "| 8. Liat Semua Turnamen                   |"<<endl;
        cout << "| 0. Kembali                               |"<<endl;
        cout << "============================================"<<endl;
        cout << "Masukkan Pilihan Anda: ";
        cin >> pilih;
        if (pilih == 1) {
            inputDataTurnamen(x);
            p = createElemenTurnamen(x);
            insertFirstTurnamen(L, p);
        }else if (pilih == 2) {
            inputDataTurnamen(x);
            p = createElemenTurnamen(x);
            insertLastTurnamen(L, p);
        }else if (pilih == 3) {
            cout << "Insert setelah turnamen bernama: ";
            cin.ignore(1000, '\n');
            getline(cin, nama);

            prec = searchTurnamenByNama(L, nama);
            if (prec != nullptr) {
                inputDataTurnamen(x);
                p = createElemenTurnamen(x);
                insertAfterTurnamen(L, prec, p);
                cout << "Turnamen berhasil ditambahkan.\n";
            } else {
                cout << "Turnamen tidak ditemukan\n";
            }
        }else if (pilih == 4) {
            deleteFirstTurnamen(L, p);
            if (p != nullptr){
                cout << "Turnamen dengan nama: "<< p->info.namaTurnamen << " berhasil dihapus";
            }else{
                cout << "List kosong";
            }
        }else if (pilih == 5) {
            deleteLastTurnamen(L, p);
            if (p != nullptr){
                cout << "Turnamen dengan nama: "<< p->info.namaTurnamen << " berhasil dihapus";
            }else{
                cout << "List kosong";
            }
        }else if (pilih == 6) {
            cout << "Delete setelah turnamen bernama: ";
            cin.ignore(1000, '\n');
            getline(cin, nama);
            prec = searchTurnamenByNama(L, nama);
            deleteAfterTurnamen(L, prec, p);
            if (p != nullptr){
                cout << "Turnamen dengan nama: "
                << p->info.namaTurnamen
                << " berhasil dihapus";
            }else{
                cin >> nama;
                prec = searchTurnamenByNama(L, nama);
                deleteAfterTurnamen(L, prec, p);
            }
        }else if (pilih == 7) {
            cout << "Cari tahun: ";
            cin >> tahun;

            adrTurnamen P = L.first;
            bool ketemu = false;

            while (P != nullptr) {
                if (P->info.tahun == tahun) {
                    cout << "- " << P->info.namaTurnamen << endl;
                    ketemu = true;
                }
                P = P->next;
            }
            if (!ketemu) {
            cout << "Tidak ditemukan\n";
            }

        }else if (pilih == 8) {
            displayTurnamen(L);
        }else if (pilih == 0) {
            cout << "Kembali ke menu admin";
        }else {
            cout << "Pilihan tidak valid!";
        }
        cout << endl;
    }
}
void menuPemain(ListTurnamen &L){
    int pilih = 1;
    string namaTurnamen, id, nama;
    int score;
    adrTurnamen T;
    adrPemain P, prec;

    while (pilih != 0) {
        cout << "============================================" << endl;
        cout << "|               MENU PEMAIN                |" << endl;
        cout << "============================================" << endl;
        cout << "| 1. Insert First Pemain                   |" << endl;
        cout << "| 2. Insert Last Pemain                    |" << endl;
        cout << "| 3. Insert After Pemain                   |" << endl;
        cout << "| 4. Delete First Pemain                   |" << endl;
        cout << "| 5. Delete Last Pemain                    |" << endl;
        cout << "| 6. Delete After Pemain                   |" << endl;
        cout << "| 7. Search Pemain                         |" << endl;
        cout << "| 8. Liat Pemain dalam Turnamen            |" << endl;
        cout << "| 0. Kembali                               |" << endl;
        cout << "============================================" << endl;
        cout << "Masukkan Pilihan Anda: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Nama Turnamen: ";
            cin.ignore(1000, '\n');
            getline(cin, namaTurnamen);
            T = searchTurnamenByNama(L, namaTurnamen);
            if (T != nullptr) {
                cout << "ID Pemain   : "; cin >> id;
                cout << "Nama Pemain : "; cin >> nama;
                cout << "Score       : "; cin >> score;
                if (sudahIkutTahunIni(L, id, T->info.tahun)) {
                    cout << "Pemain sudah mengikuti turnamen lain di tahun yang sama!\n";
                } else {
                    P = createElmPemain(id, nama, score);
                    insertFirstPemain(T, P);
                    cout << "Pemain berhasil ditambahkan.\n";
                }

                P = createElmPemain(id, nama, score);
                insertFirstPemain(T, P);
            } else {
                cout << "Turnamen tidak ditemukan\n";
            }
        }
        else if (pilih == 2) {
            cout << "Nama Turnamen: ";
            cin.ignore(1000, '\n');
            getline(cin, namaTurnamen);
            T = searchTurnamenByNama(L, namaTurnamen);

            if (T != nullptr) {
                cout << "ID Pemain   : "; cin >> id;
                cout << "Nama Pemain : "; cin >> nama;
                cout << "Score       : "; cin >> score;
                if (sudahIkutTahunIni(L, id, T->info.tahun)) {
                    cout << "Pemain sudah mengikuti turnamen lain di tahun yang sama!\n";
                } else {
                    P = createElmPemain(id, nama, score);
                    insertLastPemain(T, P);
                    cout << "Pemain berhasil ditambahkan.\n";
                }
                P = createElmPemain(id, nama, score);
                insertLastPemain(T, P);
            } else {
                cout << "Turnamen tidak ditemukan\n";
            }
        }
        else if (pilih == 3) {
            cout << "Nama Turnamen: ";
            cin.ignore(1000, '\n');
            getline(cin, namaTurnamen);
            T = searchTurnamenByNama(L, namaTurnamen);

            if (T != nullptr) {
                cout << "Insert setelah ID Pemain: ";
                cin >> id;
                prec = findPemain(T, id);

                if (prec != nullptr) {
                    cout << "ID Pemain   : "; cin >> id;
                    cout << "Nama Pemain : "; cin >> nama;
                    cout << "Score       : "; cin >> score;
                    if (sudahIkutTahunIni(L, id, T->info.tahun)) {
                        cout << "Pemain sudah mengikuti turnamen lain di tahun yang sama!\n";
                    } else {
                        P = createElmPemain(id, nama, score);
                        insertAfterPemain(T, prec, P);
                        cout << "Pemain berhasil ditambahkan.\n";
                    }
                    P = createElmPemain(id, nama, score);
                    insertAfterPemain(T, prec, P);
                } else {
                    cout << "Pemain tidak ditemukan\n";
                }
            } else {
                cout << "Turnamen tidak ditemukan\n";
            }
        }
        else if (pilih == 4) {
            cout << "Nama Turnamen: ";
            cin.ignore(1000, '\n');
            getline(cin,namaTurnamen);
            T = searchTurnamenByNama(L, namaTurnamen);

            if (T != nullptr) {
                deleteFirstPemain(T, P);
                if (P != nullptr)
                    cout << "Pemain pertama berhasil dihapus\n";
                else
                    cout << "Belum ada pemain\n";
            } else {
                cout << "Turnamen tidak ditemukan\n";
            }
        }
        else if (pilih == 5) {
            cout << "Nama Turnamen: ";
            cin.ignore(1000, '\n');
            getline(cin,namaTurnamen);
            T = searchTurnamenByNama(L, namaTurnamen);

            if (T != nullptr) {
                deleteLastPemain(T, P);
                if (P != nullptr)
                    cout << "Pemain terakhir berhasil dihapus\n";
                else
                    cout << "Belum ada pemain\n";
            } else {
                cout << "Turnamen tidak ditemukan\n";
            }
        }
        else if (pilih == 6) {
            cout << "Nama Turnamen: ";
            cin.ignore(1000, '\n');
            getline(cin,namaTurnamen);
            T = searchTurnamenByNama(L, namaTurnamen);

            if (T != nullptr) {
                cout << "Delete setelah ID Pemain: ";
                cin >> id;
                prec = findPemain(T, id);
                if (prec != nullptr) {
                    deleteAfterPemain(T, prec, P);
                    if (P != nullptr)
                        cout << "Pemain berhasil dihapus\n";
                    else
                        cout << "Tidak ada pemain setelahnya\n";
                } else {
                    cout << "Pemain tidak ditemukan\n";
                }
            } else {
                cout << "Turnamen tidak ditemukan\n";
            }
        }
        else if (pilih == 7) {
            cout << "Nama Turnamen: ";
            cin.ignore(1000, '\n');
            getline(cin,namaTurnamen);
            T = searchTurnamenByNama(L, namaTurnamen);
            if (T != nullptr) {
                cout << "Cari ID Pemain: ";
                cin >> id;
                P = findPemain(T, id);
                if (P != nullptr) {
                    cout << "ID    : " << P->idPemain << endl;
                    cout << "Nama  : " << P->nama << endl;
                    cout << "Score : " << P->score << endl;
                } else {
                    cout << "Pemain tidak ditemukan\n";
                }
            } else {
                cout << "Turnamen tidak ditemukan\n";
            }
        }
        else if (pilih == 8) {
            cout << "Nama Turnamen: ";
            cin.ignore(1000, '\n');
            getline(cin,namaTurnamen);
            T = searchTurnamenByNama(L, namaTurnamen);
            if (T != nullptr)
                printPemain(T);
            else
                cout << "Turnamen tidak ditemukan\n";
        }
        else if (pilih == 0) {
            cout << "Kembali ke menu admin\n";
        }
        else {
            cout << "Pilihan tidak valid!\n";
        }

        cout << endl;
    }
}
void menuUser(ListTurnamen &L){
    int pilih = 1;
    string namaTurnamen, id, nama;
    int score, tahun;
    adrTurnamen T;
    adrPemain P;

    while (pilih != 0) {
    cout << "============================================"<< endl;
    cout << "|            MENU USER (STUDY CASE)        |"<< endl;
    cout << "============================================"<< endl;
    cout << "| 1. Lihat Semua Turnamen                  |"<< endl;
    cout << "| 2. Tambah Pemain ke Turnamen             |"<< endl;
    cout << "| 3. Hapus Pemain dari Turnamen            |"<< endl;
    cout << "| 4. Lihat Pemain dalam Turnamen           |"<< endl;
    cout << "| 5. Pemain Score Tertinggi per Turnamen   |"<< endl;
    cout << "| 6. Pemain Score Tertinggi Semua Tahun    |"<< endl;
    cout << "| 0. Kembali                               |"<< endl;
    cout << "============================================"<< endl;
    cout << "Pilih: ";
    cin >> pilih;
    if (pilih == 1) {
        displayTurnamen(L);
    }else if (pilih == 2) {
        cin.ignore(1000,'\n');
        cout << "Nama Turnamen : ";
        getline(cin, namaTurnamen);

        T = searchTurnamenByNama(L, namaTurnamen);
        if (T != nullptr) {
            cout << "ID Pemain   : ";
            cin >> id;
            cout << "Nama Pemain : ";
            cin >> nama;
            cout << "Score       : ";
            cin >> score;
            if (sudahIkutTahunIni(L, id, T->info.tahun)) {
                cout << "Pemain sudah ikut turnamen lain di tahun "
                     << T->info.tahun << endl;
            } else {
                P = createElmPemain(id, nama, score);
                insertLastPemain(T, P);
                cout << "Pemain berhasil ditambahkan\n";
            }
        } else {
            cout << "Turnamen tidak ditemukan\n";
        }
    }else if (pilih == 3) {
        cin.ignore(1000,'\n');
        cout << "Nama Turnamen : ";
        getline(cin, namaTurnamen);
        T = searchTurnamenByNama(L, namaTurnamen);

        if (T != nullptr) {
            cout << "ID Pemain : ";
            cin >> id;
            deletePemainByID(T, id);
            cout << "Pemain dihapus (jika ada)\n";
        } else {
            cout << "Turnamen tidak ditemukan\n";
        }
    }else if (pilih == 4) {
        cin.ignore(1000,'\n');
        cout << "Nama Turnamen : ";
        getline(cin, namaTurnamen);
        T = searchTurnamenByNama(L, namaTurnamen);
        if (T != nullptr)
            printPemain(T);
        else
            cout << "Turnamen tidak ditemukan\n";
    }else if (pilih == 5) {
        cin.ignore(1000,'\n');
        cout << "Nama Turnamen : ";
        getline(cin, namaTurnamen);
        T = searchTurnamenByNama(L, namaTurnamen);
        if (T != nullptr && T->firstPemain != nullptr) {
            adrPemain max = T->firstPemain;
            adrPemain P = max->next;
            while (P != nullptr) {
                if (P->score > max->score)
                    max = P;
                P = P->next;
            }
            cout << "Pemain terbaik:\n";
            cout << max->nama << " | Score: " << max->score << endl;
        } else {
            cout << "Belum ada pemain\n";
        }
    }else if (pilih == 6) {
        adrTurnamen t = L.first;
        adrPemain best = nullptr;
        while (t != nullptr) {
            adrPemain p = t->firstPemain;
            while (p != nullptr) {
                if (best == nullptr || p->score > best->score)
                    best = p;
                p = p->next;
            }
            t = t->next;
        }if (best != nullptr) {
            cout << "Pemain terbaik sepanjang tahun:\n";
            cout << best->nama << " | Score: " << best->score << endl;
        }else {
            cout << "Belum ada data pemain\n";
        }
    }else if (pilih == 0) {
        cout << "Kembali ke main menu\n";
    }else {
        cout << "Pilihan tidak valid\n";
    }
    cout << endl;
    }
}
void inputDataTurnamen(Turnamen &x) {
    cout << "Nama Turnamen   : ";
    cin >> x.namaTurnamen;
    cout << "Lokasi          : ";
    cin >> x.lokasi;
    cout << "Tanggal Mulai   : ";
    cin >> x.tanggalMulai;
    cout << "Tanggal Selesai : ";
    cin >> x.tanggalSelesai;
    cout << "Tahun           : ";
    cin >> x.tahun;
    cout << "Kategori        : ";
    cin >> x.kategori;
}

