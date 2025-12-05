#ifndef AKUN_H_INCLUDED
#define AKUN_H_INCLUDED

#include <string>
using namespace std;

typedef struct akunNode *adrAkun;

struct akunNode {
    string username;
    string password;
    string role;
    adrAkun next;
};

struct ListAkun {
    adrAkun first;
};

void createAkunList(ListAkun &LA);
adrAkun createAkunNode(string username, string password, string role);
void insertAkun(ListAkun &LA, adrAkun A);

adrAkun login(ListAkun LA, string username, string password);
void registerAdmin(ListAkun &LA, string username, string password);
void registerUser(ListAkun &LA, string username, string password);

#endif // AKUN_H_INCLUDED
