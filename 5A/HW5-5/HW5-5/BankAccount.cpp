#include "BankAccount.h"

BankAccount::BankAccount(double initialBalance)
{
    if (initialBalance>=1000) {
        balance=initialBalance+10;
    }else{
        balance=initialBalance;
    }
}

void BankAccount::deposit(double amount)
{
    balance+=amount;
}

void BankAccount::withdraw(double amount)
{
    balance-=amount;
}

double BankAccount::getBalance()
{
    return balance;
}


