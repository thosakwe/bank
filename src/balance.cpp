#include "balance.h"

Account* searchForAccount(vector<Account*> accounts, int id) {
    for (Account *account : accounts) {
        if (account->id == id) {
            return account;
        }
    }

    return nullptr;
}

int checkBalance() {
    vector<Account*> database = loadAccounts();
    int account_id;

    printf("Welcome to Bank++! Enter your account number to view your balance: ");
    scanf("%d", &account_id);
    Account *account = searchForAccount(database, account_id);

    if (!account) {
        fprintf(stderr, "No record found for a user with ID %d.\n", account_id);
        return 1;
    }

    printf("Hello, %s. Your balance is $%.2f\n", account->name.c_str(), account->balance / 100.0F);
    printf("Thank you for saving with Bank++! Hope to see you soon!\n");

    return 0;
}