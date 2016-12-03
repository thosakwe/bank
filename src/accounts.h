#ifndef H_ACCOUNTS
#define H_ACCOUNTS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Account {
    int id;
    const char* name;
    long balance;
    struct Account* next;
} Account;

void resetAccount(Account*);
Account* loadAccounts();

#endif