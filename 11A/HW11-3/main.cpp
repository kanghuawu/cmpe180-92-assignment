#include <iostream>
#include "hash.hpp"

using namespace std;

void print(const vector<int>& table)
{
    for (int i = 0; i < table.size(); i++) {
        if (table[i] == EMPTY) cout << "EMPTY";
        else cout << table[i];
        if (i < table.size() - 1) cout << ", ";
        else cout << endl;
    }
}

int main()
{
    //#11-3
//    vector<int> table1 = { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY };
//    insert(table1, 42);
//    print(table1);
//    cout << "1 Expected: EMPTY, EMPTY, 42, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY" << endl;
//    
//    vector<int> table2 = { EMPTY, EMPTY, 52, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY };
//    insert(table2, 42);
//    print(table2);
//    cout << "2 Expected: EMPTY, EMPTY, 52, 42, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY" << endl;
//    
//    vector<int> table3 = { EMPTY, EMPTY, 52, 43, 53, 63, 66, 74, 88, 89 };
//    insert(table3, 42);
//    print(table3);
//    cout << "3 Expected: 42, EMPTY, 52, 43, 53, 63, 66, 74, 88, 89" << endl;
//    insert(table3, 42);
//    print(table3);
//    cout << "4 Expected: 42, EMPTY, 52, 43, 53, 63, 66, 74, 88, 89" << endl;
//    insert(table3, 41);
//    print(table3);
//    cout << "5 Expected: 42, 41, 52, 43, 53, 63, 66, 74, 88, 89" << endl;
//    
//    insert(table3, 40);
//    print(table3);
//    cout << "6 Expected: 42, 41, 52, 43, 53, 63, 66, 74, 88, 89" << endl;
    
    //#11-4
    vector<int> table1 = { 10, 20, 32, 42, 54, EMPTY, EMPTY, EMPTY, EMPTY, 99 };
    remove(table1, 54);
    print(table1);
    cout << "Expected: 10, 20, 32, 42, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 99" << endl;
    remove(table1, 10);
    print(table1);
    cout << "Expected: 20, EMPTY, 32, 42, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 99" << endl;
    remove(table1, 9);
    print(table1);
    cout << "Expected: 20, EMPTY, 32, 42, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 99" << endl;
    vector<int> table2 = { 10, 20, 32, 42, 50, 55, 52, EMPTY, EMPTY, 99 };
    remove(table2, 32);
    print(table2);
    cout << "Expected: 10, 20, 42, 50, 52, 55, EMPTY, EMPTY, EMPTY, 99" << endl;
    
    return 0;
}




