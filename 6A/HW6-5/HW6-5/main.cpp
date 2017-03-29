#include <iostream>

using namespace std;

#include "path.h"

int main()
{
    Path p(4);
    p.set(0, 3, 1);
    p.set(1, 4, 1);
    p.set(2, 5, 9);
    p.set(3, 2, 6);
    cout << p.getX(2) << " " << p.getY(2) << endl;
    cout << "Expected: 5 9" << endl;
    Path q(1);
    q = p;
    cout << q.getX(0) << " " << q.getY(0) << endl;
    cout << "Expected: 3 1" << endl;
    p.set(2, 9, 7);
    cout << p.getX(2) << " " << p.getY(2) << endl;
    cout << "Expected: 9 7" << endl;
    cout << q.getX(2) << " " << q.getY(2) << endl;
    cout << "Expected: 5 9" << endl;
    
    return 0;
}

