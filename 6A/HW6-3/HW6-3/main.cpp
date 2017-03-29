#include <iostream>
#include <sstream>

using namespace std;

#include "time.h"

int main()
{
    Time t1(9, 15);
    Time t2(10, 0);
    Time t3(23, 59);
    cout << "t1: " << t1 << endl;
    cout << "Expected: 09:15" << endl;
    cout << "t2: " << t2 << endl;
    cout << "Expected: 10:00" << endl;
    cout << "t3: " << t3 << endl;
    cout << "Expected: 23:59" << endl;
    stringstream sout;
    sout << "t1: " << t1 << endl;
    cout << sout.str();
    cout << "Expected: 09:15" << endl;
    
    return 0;
}

