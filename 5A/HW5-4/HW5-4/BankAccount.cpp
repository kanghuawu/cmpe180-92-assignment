#include "BankAccount.h"

BankAccount::BankAccount()
{
    balance = 0;
    transactions = 0;
}

void BankAccount::deposit(double amount)
{
    balance+=amount;
    transactions+=1;
}

// Declare the withdraw method
void BankAccount::withdraw(double amount)
{
    balance-=amount;
    transactions+=1;
}

double BankAccount::getBalance()
{
    return balance;
}

double BankAccount::getTransactionCount()
{
    return transactions;
}
