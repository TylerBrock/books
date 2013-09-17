// bank_account.h -- class representing a bank account
#ifndef BANK_ACCOUNT_H_
#define BANK_ACCOUNT_H_

#include <string>

class BankAccount
{
    private:
        std::string name;
        std::string acctnum;
        double balance;
    public:
        BankAccount(const std::string & client, const std::string & num, double bal = 0.0);
        void show() const;
        void deposit(double amount);
        void withdraw(double amount);
};

#endif
