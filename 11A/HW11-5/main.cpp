#include <iostream>
#include <vector>

using namespace std;
int hashCode(int x, int n);
void insert(vector<vector<int>>& table, int element);

void print(const vector<vector<int>>& table)
{
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[i].size(); j++) {
            cout << table[i][j] << " ";
        }
        if (i < table.size() - 1) cout << "| ";
        else cout << endl;
    }
}

int main()
{
    vector<vector<int>> table1(10);
    insert(table1, 42);
    print(table1);
    cout << "Expected:  | | 42 | | | | | | |" << endl;
    insert(table1, 52);
    print(table1);
    cout << "Expected:  | | 42 52 | | | | | | |" << endl;
    insert(table1, 43);
    print(table1);
    cout << "Expected:  | | 42 52 | 43 | | | | | |" << endl;
    insert(table1, 43);
    print(table1);
    cout << "Expected:  | | 42 52 | 43 | | | | | |" << endl;
    return 0;
}

int hashCode(int x, int n)
{
    if (x >= 0) return x % n; else return -x % n;
}

/**
 Here, we implement chaining, except that we use a vector,
 not a linked list, for the sequences of elements with the same
 hash code. Just implement the insert method. If an element is not
 found, add it to the end of its chain.
 */
void insert(vector<vector<int>>& table, int element)
{
    vector<int> hashvec = table.at(hashCode(element, table.size()));
    bool notfound = true;
    for (int i = 0; i < hashvec.size(); i++) {
        if(hashvec.at(i) == element) notfound = false;
    }
    if(notfound) table.at(hashCode(element, table.size())).push_back(element);
}
