#include "BankAccount.hpp"

BankAccount::BankAccount()
{
    balance = 0;
}

void BankAccount::deposit(double amount)
{
    balance+=amount;
}

// Declare the withdraw method
void BankAccount::withdraw(double amount)
{
    balance-=amount+1;
}

double BankAccount::getBalance()
{
    return balance;
}
