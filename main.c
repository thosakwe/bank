#include <stdio.h>
#include <string.h>
#include "src/balance.h"

int printUsage() {
    printf("usage: bank <mode>\n");
    printf("where mode is one of:\n\n");
    printf("    balance     Check an account's balance.\n");
    printf("    deposit     Add to your balance.\n");
    printf("    history     View transaction history.\n");
    printf("    register    Register a new account with the bank.\n");
    printf("    withdraw    Remove money from your account.\n");
    return 1;
}

int main(int argc, char** argv) {
    if (argc <= 1) {
        return printUsage();
    }

    if (!strcmp(argv[1], "balance")) {
        return checkBalance();
    } else {
        return printUsage();
    }
}
