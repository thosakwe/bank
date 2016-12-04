#ifndef H_ACCOUNTS
#define H_ACCOUNTS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Account {
public:
    int id = -1;
    string name;
    long balance = -1;
    void dump();
};

vector<Account*> loadAccounts();

#endif