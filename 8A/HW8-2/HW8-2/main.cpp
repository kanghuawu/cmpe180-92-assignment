#include <iostream>
#include "Bug.h"
#include "SleepyBug.h"

using namespace std;

int main()
{
    Bug* sleepy = new SleepyBug();
    sleepy->move(5);
    cout << sleepy->getPosition() << endl;
    cout << "Expected: 5" << endl;
    sleepy->move(5);
    sleepy->move(5);
    cout << sleepy->getPosition() << endl;
    cout << "Expected: 15" << endl;
    sleepy->move(5);
    cout << sleepy->getPosition() << endl;
    cout << "Expected: 15" << endl;
    sleepy->move(10);
    cout << sleepy->getPosition() << endl;
    cout << "Expected: 25" << endl;
    sleepy->move(5);
    sleepy->move(5);
    sleepy->move(5);
    sleepy->move(5);
    cout << sleepy->getPosition() << endl;
    cout << "Expected: 40" << endl;
}   


