#include <iostream>
using namespace std;

#include "Seq.h"

void fun()
{
    Seq seq1(4);
    Seq seq2 = seq1;
    seq2.set(0, 1);
    seq1.show();
    cout << "Expected: [0, 0, 0, 0] 8 boxes" << endl;
    seq2.show();
    cout << "Expected: [1, 0, 0, 0] 8 boxes" << endl;
}

int main()
{
    fun();
    Seq seq3(1);
    seq3.show();
    cout << "Expected: [0] 1 boxes" << endl;
    Seq seq4(2);
    seq4 = seq3;
    seq3.set(0, 2);
    seq4.show();
    cout << "Expected: [0] 2 boxes" << endl;
    return 0;
}

