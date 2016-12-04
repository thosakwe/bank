#include "accounts.h"

void Account::dump() {
    printf("User #%d: %s\n", this->id, this->name.c_str());
    printf("Balance: $%.2f\n", this->balance / 100.0);
}

vector<Account*> loadAccounts() {
    vector<Account*> accounts;
    FILE *csv = fopen("accounts.csv", "r");
    char* buf, trash;
    long int len;
    string name;

    fseek(csv, 0, SEEK_END);
    len = ftell(csv);
    fseek(csv, 0, SEEK_SET);
    buf = (char*) malloc(sizeof(char) * len);
    fread(buf, len, 1, csv);
    fclose(csv);

    char *pch = strtok(buf, "\n");
    
    // Skip headers
    pch = strtok(NULL, "\n");

    while (pch) {
        Account *account = new Account();
        stringstream ss(pch);

        ss >> account->id;
        ss >> trash;
        ss >> account->balance;
        ss >> trash;
        
        while(ss >> name) {
            if (account->name.length() > 0) {
                account->name += " ";
            }

            account->name += name;
        }

        accounts.push_back(account);
        pch = strtok(NULL, "\n");
    }

    free(buf);
    return accounts;
}