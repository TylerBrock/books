// bank_account.cpp -- bank account implementation
#include <iostream>
#include "bank_account.h"

BankAccount::BankAccount(const std::string & client, const std::string & num, double bal)
{
    name = client;
    acctnum = num;
    balance = bal;
}

void BankAccount::show() const
{
    std::cout << "Bank Account of: " << name << std::endl;
    std::cout << "Account number: " << acctnum << std::endl;
    std::cout << "Balance: " << balance << std::endl;
}

void BankAccount::deposit(double amount)
{
    balance += amount;
}

void BankAccount::withdraw(double amount)
{
    balance -= amount;
}
