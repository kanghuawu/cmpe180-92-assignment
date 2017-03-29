#include <iostream>
#include "Bug.h"
#include "DeadBug.h"
#include "BugParade.h"

using namespace std;

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}

int main()
{
    BugParade parade;
    parade.add(new Bug(3));
    parade.add(new DeadBug(4));
    parade.add(new Bug(5));
    parade.add(new DeadBug(6));
    vector<int> results = parade.moveAll(2);
    print(results);
    cout << "Expected: 5 4 7 6" << endl;
    parade.add(new DeadBug(7));
    print(parade.moveAll(-2));
    cout << "Expected: 3 4 5 6 7" << endl;
    return 0;
}

