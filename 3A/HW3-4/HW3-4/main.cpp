#include <iostream>
#include <vector>
using namespace std;


vector<int> rot(const vector<int>& a);

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
    vector<int> result = rot(values);
    print(result);
    cout << "Expected: {1, 4, 1, 5, 9, 2, 6, 3}" << endl;
    
    // Don't expect to change values
    print(values);
    cout << "Expected: {3, 1, 4, 1, 5, 9, 2, 6}" << endl;
    
    values = { 1, -1 };
    result = rot(values);
    print(result);
    cout << "Expected: {-1, 1}" << endl;
    
    values = { 42 };
    result = rot(values);
    print(result);
    cout << "Expected: {42}" << endl;
    
    values = { };
    result = rot(values);
    print(result);
    cout << "Expected: {}" << endl;
}


