#include <iostream>

using namespace std;

#include "time.h"

int main()
{
    Time t1(9, 15);
    Time t2(10, 0);
    cout << t2 - t1 << endl;
    cout << "Expected: 45" << endl;
    cout << t1 - t2 << endl;
    cout << "Expected: -45" << endl;
    Time t3(23, 59);
    cout << t3 - t1 << endl;
    cout << "Expected: 884" << endl;
    cout << t1 - t3 << endl;
    cout << "Expected: -884" << endl;
    
    return 0;
}

