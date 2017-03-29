#include <iostream>
#include <cmath>

using namespace std;

#include "BankAccount.h"

int main()
{
    BankAccount account1;
    account1.deposit(1000);
    account1.withdraw(100);
    cout << "Balance: " << account1.getBalance() << endl;
    cout << "Expected: 900" << endl;
    cout << account1.getTransactionCount() << endl;
    cout << "Expected: 2" << endl;
    
    BankAccount account2;
    account2.deposit(1000);
    account2.withdraw(100);
    account2.withdraw(100);
    cout << "Balance: " << account2.getBalance() << endl;
    cout << "Expected: 800" << endl;
    cout << account2.getTransactionCount() << endl;
    cout << "Expected: 3" << endl;
}
