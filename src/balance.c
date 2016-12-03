#include "balance.h"

void dumpAccounts(Account* account) {
    Account *cur = account;

    while (cur) {
        printf("User #%d: %s, $%.2f\n", cur->id, cur->name, cur->balance / 100.0);
        cur = cur->next;
    }
}

Account* searchForAccount(Account* account, int id) {
    dumpAccounts(account);
    return 0;

    if (account == NULL) {
        return NULL;
    }

    Account *search = account;

    while (search != NULL) {
        if (search->id == id) {
            return search;
        } else {
            printf("User #%d (name: %s) does not match ID %d.\n", search->id, search->name, id);
        }

        if (search) {
            search = search->next;
        }
    }

    return NULL;
}

int checkBalance() {
    Account *database = loadAccounts();
    int account_id;

    if (!database) {
        fprintf(stderr, "Could not load account database.\n");
        return 1;
    }

    printf("Welcome to Bank++! Enter your account number to view your balance: ");
    scanf("%d", &account_id);
    printf("Searching database for account #%d...\n", account_id);
    Account *account = searchForAccount(database, account_id);

    if (!account) {
        fprintf(stderr, "No record found for a user with ID %d.\n", account_id);
        return 1;
    }

    printf("Your balance: $%.2f\n", account->balance / 100.0F);
    printf("Thank you for saving with Bank++! Hope to see you soon!\n");

    return 0;
}