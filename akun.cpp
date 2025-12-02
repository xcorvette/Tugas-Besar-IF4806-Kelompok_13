#include <iostream>
#include "akun.h"

using namespace std;

void createAkunList(ListAkun &LA) {
    LA.first = nullptr;
}

adrAkun createAkunNode(string username, string password, string role) {
    adrAkun A = new akunNode;
    A->username = username;
    A->password = password;
    A->role = role;
    A->next = nullptr;
    return A;
}

void insertAkun(ListAkun &LA, adrAkun A) {
    A->next = LA.first;
    LA.first = A;
}

void registerAdmin(ListAkun &LA, string username, string password) {
    insertAkun(LA, createAkunNode(username, password, "admin"));
    cout << ">> Admin registered!\n\n";
}

void registerUser(ListAkun &LA, string username, string password) {
    insertAkun(LA, createAkunNode(username, password, "user"));
    cout << ">> User registered!\n\n";
}

adrAkun login(ListAkun LA, string username, string password) {
    adrAkun A = LA.first;
    while (A != nullptr) {
        if (A->username == username && A->password == password) {
            return A;
        }
        A = A->next;
    }
    return nullptr;
}
