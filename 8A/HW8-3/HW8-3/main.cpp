#include <iostream>
#include "Bug.h"
#include "HungryBug.h"

using namespace std;

int main()
{
    HungryBug* hungry = new HungryBug(3); // Starts out with three food units
    hungry->move(5);
    cout << hungry->getPosition() << endl;
    cout << "Expected: 5" << endl;
    hungry->move(5);
    hungry->move(5);
    cout << hungry->getPosition() << endl;
    cout << "Expected: 15" << endl;
    hungry->move(5);
    cout << hungry->getPosition() << endl;
    cout << "Expected: 15" << endl;
    hungry->eat(2);
    hungry->move(10);
    cout << hungry->getPosition() << endl;
    cout << "Expected: 25" << endl;
    hungry->move(5);
    hungry->move(5);
    cout << hungry->getPosition() << endl;
    cout << "Expected: 30" << endl;
}

