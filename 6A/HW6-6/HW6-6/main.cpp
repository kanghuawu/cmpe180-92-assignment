#include <iostream>

using namespace std;

#include "interval.h"

int main()
{
    Interval r(1, 4);
    Interval s(2, 5);
    Interval t = r & s;
    cout << t.toString() << endl;
    cout << "Expected: [2, 4)" << endl;
    
    r = Interval(1, 2);
    s = Interval(3, 4);
    t = r & s;
    cout << t.toString() << endl;
    cout << "Expected: [0, 0)" << endl;
    
    t = r + s;
    cout << t.toString() << endl;
    cout << "Expected: [1, 4)" << endl;
    
    t = (r & s) + r;
    cout << t.toString() << endl;
    cout << "Expected: [1, 2)" << endl;
    
    t = s + (r & s);
    cout << t.toString() << endl;
    cout << "Expected: [3, 4)" << endl;
    
    return 0;
}

