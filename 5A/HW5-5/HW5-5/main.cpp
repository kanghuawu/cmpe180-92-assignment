#include <iostream>
#include <cmath>

using namespace std;

#include "BankAccount.h"

int main()
{
    BankAccount account1(10000);
    account1.deposit(1000);
    cout << "Balance: " << account1.getBalance() << endl;
    cout << "Expected: 11010" << endl;
    
    BankAccount account2(999);
    account2.deposit(100);
    cout << "Balance: " << account2.getBalance() << endl;
    cout << "Expected: 1099" << endl;
    
    BankAccount account3(1000);
    account3.deposit(100);
    cout << "Balance: " << account3.getBalance() << endl;
    cout << "Expected: 1110" << endl;
}

