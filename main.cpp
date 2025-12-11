#include <iostream>
#include "header.h"
#include "akun.h"
#include <limits>

using namespace std;

void adminMenu(ListTurnamen &LT, ListAkun &LA);
void userMenu(ListTurnamen &LT);

// REGISTER

void menuRegistrasi(ListAkun &LA) {
    int pilih;

    do {
        cout << "\n===== REGISTER MENU =====\n";
        cout << "1. Register Admin\n";
        cout << "2. Register User\n";
        cout << "0. Kembali\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            string usn, pw;
            cout << "Username: ";
            cin >> usn;
            cout << "Password: ";
            cin >> pw;
            registerAdmin(LA, usn, pw);
        }
        else if (pilih == 2) {
            string usn, pw;
            cout << "Username: ";
            cin >> usn;
            cout << "Password: ";
            cin >> pw;
            registerUser(LA, usn, pw);
        }
        else if (pilih == 0) {
            cout << "Kembali ke menu utama...\n";
        }
        else {
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilih != 0);
}


// LOGIN

void menuLogin(ListAkun &LA, ListTurnamen &LT) {
    string u, p;
    cout << "\n=== LOGIN ===\n";
    cout << "Username: "; cin >> u;
    cout << "Password: "; cin >> p;

    adrAkun acc = login(LA, u, p);

    if (acc == nullptr) {
        cout << ">> Login gagal! Username/password salah.\n";
        return;
    }

    cout << "\n>> Login sebagai [" << acc->role << "]\n";

    if (acc->role == "admin")
        adminMenu(LT, LA);
    else
        userMenu(LT);
}

// ADMIN

void adminMenu(ListTurnamen &LT, ListAkun &LA) {
    int pilih;

    do {
        cout << "\n===== ADMIN MENU =====\n";
        cout << "1. Tambah Turnamen\n";
        cout << "2. Tampilkan Semua Turnamen\n";
        cout << "3. Kelola Pemain dalam Turnamen\n";
        cout << "0. Logout\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (pilih == 1) {
            Turnamen x;

            cout << "\n=== INPUT DATA TURNAMEN ===\n";

            cout << "Nama turnamen : ";
            getline(cin, x.namaTurnamen);

            cout << "Lokasi        : ";
            getline(cin, x.lokasi);

            cout << "Tanggal Mulai : ";
            getline(cin, x.tanggalMulai);

            cout << "Tanggal Selesai : ";
            getline(cin, x.tanggalSelesai);

            cout << "Tahun         : ";
            cin >> x.tahun;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Kategori      : ";
            getline(cin, x.kategori);

            adrTurnamen T = createElemenTurnamen(x);
            insertLastTurnamen(LT, T);

            cout << "\n>> Turnamen berhasil ditambahkan!\n";
        }

        else if (pilih == 2) {
            displayTurnamen(LT);
        }

        else if (pilih == 3) {
            string namaT;

            cout << "Masukkan nama turnamen: ";
            getline(cin, namaT);

            adrTurnamen T = searchTurnamenByNama(LT, namaT);
            if (!T) {
                cout << ">> Turnamen tidak ditemukan!\n";
            }
            else {
                int m;
                do {
                    cout << "\n=== KELOLA PEMAIN: " << T->info.namaTurnamen << " ===\n";
                    cout << "1. Tambah Pemain (First)\n";
                    cout << "2. Tambah Pemain (Last)\n";
                    cout << "3. Hapus Pemain by ID\n";
                    cout << "4. Cari Pemain\n";
                    cout << "5. Tampilkan Semua Pemain\n";
                    cout << "0. Kembali\n";
                    cout << "Pilih: ";
                    cin >> m;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (m == 1 || m == 2) {
                        string id, namap;
                        int score;

                        cout << "ID Pemain   : ";
                        getline(cin, id);

                        if (sudahIkutTahunIni(LT, id, T->info.tahun)) {
                            cout << ">> Pemain sudah ikut turnamen lain tahun ini!\n";
                            continue;
                        }

                        cout << "Nama Pemain : ";
                        getline(cin, namap);

                        cout << "Score       : ";
                        cin >> score;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        adrPemain P = createElmPemain(id, namap, score);

                        if (m == 1) insertFirstPemain(T, P);
                        else insertLastPemain(T, P);

                        cout << ">> Pemain berhasil ditambahkan!\n";
                    }

                    else if (m == 3) {
                        string id;
                        cout << "ID pemain yang ingin dihapus: ";
                        getline(cin, id);

                        deletePemainByID(T, id);
                    }

                    else if (m == 4) {
                        string id;
                        cout << "ID Pemain: ";
                        getline(cin, id);

                        adrPemain P = findPemain(T, id);
                        if (!P) cout << ">> Pemain tidak ditemukan!\n";
                        else cout << "Nama: " << P->nama << ", Score: " << P->score << endl;
                    }

                    else if (m == 5) {
                        printPemain(T);
                    }

                } while (m != 0);
            }
        }

    } while (pilih != 0);
}


// USER
void userMenu(ListTurnamen &LT) {
    int pilih;

    do {
        cout << "\n===== USER MENU =====\n";
        cout << "1. Lihat Semua Turnamen\n";
        cout << "2. Cari Turnamen berdasarkan nama\n";
        cout << "0. Logout\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            displayTurnamen(LT);
        }

        else if (pilih == 2) {
            string nama;
            cout << "Nama turnamen: ";
            getline(cin, nama);

            adrTurnamen T = searchTurnamenByNama(LT, nama);
            if (T == nullptr)
                cout << ">> Tidak ditemukan!\n";
            else {
                cout << "\n--- DATA TURNAMEN ---\n";
                cout << "Nama     : " << T->info.namaTurnamen << endl;
                cout << "Lokasi   : " << T->info.lokasi << endl;
                cout << "Tahun    : " << T->info.tahun << endl;
                printPemain(T);
            }
        }

    } while (pilih != 0);
}


int main() {
    ListTurnamen LT;
    ListAkun LA;

    createListTurnamen(LT);
    createAkunList(LA);

    int pilih;

    do {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            menuRegistrasi(LA);
        }

        else if (pilih == 2) {
            adrAkun acc = menuLogin(LA);

            if (acc != nullptr) {
                if (acc->role == "admin")
                    adminMenu(LT, LA);
                else
                    userMenu(LT);
            }
        }

        else if (pilih != 0) {
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilih != 0);

    cout << "Keluar...\n";
    return 0;
}

