#include "accounts.h"

void resetAccount(Account* account) {
    account->id = -1;
    account->name = NULL;
    account->balance = -1;
    account->next = NULL;
}

Account* loadAccounts() {
    FILE *csv = fopen("accounts.csv", "r");
    char* buf;
    long int len;

    if (!csv) {
        return 0;
    }

    fseek(csv, 0, SEEK_END);
    len = ftell(csv);
    fseek(csv, 0, SEEK_SET);
    buf = (char*) malloc(sizeof(char) * len);
    fread(buf, len, 1, csv);
    fclose(csv);

    Account *root = NULL;
    Account *cur = root;
    char *pch = strtok(buf, "\n");
    
    // Skip headers
    pch = strtok(NULL, "\n");

    while (pch) {
        Account *account = (Account*) malloc(sizeof(Account));

        if (account == NULL || !account) {
            break;
        }

        // resetAccount(account);
        int result = sscanf(pch, "%d,%ld,%s", &account->id, &account->balance, account->name);

        if (result < 3) {
            fprintf(stderr, "Invalid user: '%s'\n", pch);
        }

        printf("%d,%ld,%s\n", account->id, account->balance, account->name);

        if (cur && cur != NULL) {
            cur->next = account;
            cur = account;
        } else {
            root = cur = account;
        }

        pch = strtok(NULL, "\n");
    }

    free(buf);
    return root;
}