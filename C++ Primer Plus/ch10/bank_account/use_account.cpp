// use_account.cpp -- uses BankAccount class
#include "bank_account.h"

int main()
{
    BankAccount ba("Tyler Brock", "123456789", 10);
    ba.show();
    ba.deposit(500);
    ba.show();
    ba.withdraw(1000);
    ba.show();
    return 0;
}
