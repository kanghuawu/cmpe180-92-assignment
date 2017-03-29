#include <iostream>
#include <vector>
using namespace std;
#include "prog.hpp"


void print(const vector<int>& v)
{
    cout << "{";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }
    cout << "}" << endl;
}

int main()
{
    vector<int> values = { 3, 1, 4, 1, 5, 9, 2, 6 };
    swap2(values);
    print(values);
    cout << "Expected: {3, 2, 4, 1, 5, 9, 1, 6}" << endl;
    
    vector<int> values2 = { 1, -2, 3, -4, 5, -6 };
    swap2(values2);
    print(values2);
    cout << "Expected: {1, 5, 3, -4, -2, -6}" << endl;
    
    vector<int> values3 = { 1, 2 };
    swap2(values3);
    print(values3);
    cout << "Expected: {2, 1}" << endl;
    
    vector<int> values4 = { 1 };
    swap2(values4);
    print(values4);
    cout << "Expected: {1}" << endl;
    
    vector<int> values5 = {};
    swap2(values5);
    print(values5);
    cout << "Expected: {}" << endl;
    
    return 0;
}

