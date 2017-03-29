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
    cout << p.getX(0) << " " << p.getY(0) << endl;
    cout << "Expected: 3 1" << endl;
    cout << p.getX(4) << " " << p.getY(4) << endl;
    cout << "Expected: 0 0" << endl;
    Path q(5);
    for (int i = 0; i < 5; i++) q.set(i, i, i + 1);
    for (int i = 0; i < q.getLength(); i++)
        cout << q.getX(i) << " " << q.getY(i) << " ";
    cout << endl;;
    cout << "Expected: 0 1 1 2 2 3 3 4 4 5" << endl;
    
    return 0;
}

