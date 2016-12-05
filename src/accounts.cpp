#include "accounts.h"

void Account::dump() {
    printf("User #%d: %s\n", this->id, this->name.c_str());
    printf("Balance: $%.2f\n", this->balance / 100.0);
}

vector<Account*> loadAccounts() {
    vector<Account*> accounts;
    ifstream csv("accounts.csv");
    stringstream iss;
    string name, pch;

    iss << csv.rdbuf();
    csv.close();
    
    // Skip headers
    getline(iss, pch);

    while (getline(iss, pch)) {
        Account *account = new Account();
        char *trash;
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
    }

    return accounts;
}