#include <cstring>
#include <iostream>
#include "src/balance.h"
using namespace std;

int printUsage() {
    cout << "usage: bank <mode>" << endl;
    cout << "where mode is one of:\n" << endl;
    cout << "    balance     Check an account's balance." << endl;
    cout << "    deposit     Add to your balance." << endl;
    cout << "    history     View transaction history." << endl;
    cout << "    register    Register a new account with the bank." << endl;
    cout << "    withdraw    Remove money from your account." << endl;
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
