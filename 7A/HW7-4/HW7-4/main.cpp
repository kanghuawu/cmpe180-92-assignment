#include <iostream>
using namespace std;

#include "Pair.h"

void fun()
{
    Pair pair1(1, 2);
    pair1.show();
    cout << "Expected: (1, 2) 2 boxes" << endl;
    Pair pair2 = pair1;
    pair2.show();
    cout << "Expected: (1, 2) 2 boxes" << endl;
    Pair pair3(3, 3);
    pair3.show();
    cout << "Expected: (3, 3) 3 boxes" << endl;
    pair1 = pair3;
    pair1.show();
    cout << "Expected: (3, 3) 3 boxes" << endl;
    pair2 = pair3;
    pair2.show();
    cout << "Expected: (3, 3) 1 boxes" << endl;
}

int main()
{
    fun();
    Pair pair4(0, 1);
    pair4.show();
    cout << "Expected: (0, 1) 2 boxes" << endl;
    
    return 0;
}

