#include <iostream>
#include "Bug.h"
#include "QuickBug.h"

using namespace std;

int main()
{
    Bug* quickie = new QuickBug();
    quickie->move(5);
    cout << quickie->getPosition() << endl;
    cout << "Expected: 10" << endl;
    quickie->move(10);
    cout << quickie->getPosition() << endl;
    cout << "Expected: 30" << endl;
    return 0;
}   


