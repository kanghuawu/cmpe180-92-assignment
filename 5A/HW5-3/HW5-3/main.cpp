#include <iostream>
#include <cmath>

using namespace std;

#include "BankAccount.hpp"

int main()
{
    BankAccount account1;
    account1.deposit(1000);
    account1.withdraw(100);
    cout << "Balance: " << account1.getBalance() << endl;
    cout << "Expected: 899" << endl;
    
    BankAccount account2;
    account2.deposit(1000);
    account2.withdraw(100);
    account2.withdraw(100);
    cout << "Balance: " << account2.getBalance() << endl;
    cout << "Expected: 798" << endl;
}

