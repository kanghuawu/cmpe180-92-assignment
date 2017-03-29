#include <iostream>
#include "hash.hpp"
using namespace std;

int main() {
    vector<int> table = { 42, EMPTY, 52, 43, 53, 63, 66, 74, 88, 89 };
    int x = 42;
    cout << find(table, x) << endl;
}
