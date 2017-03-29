#include <iostream>
#include "Trace.h"

using namespace std;

Trace fun(Trace t)
{
    Trace r = t;
    return r;
}

int main()
{
    Trace t("Fred");
    cout << t << endl;
    Trace u("Wilma");
    cout << u << endl;
    u = fun(t);
    cout << u << endl;
    return 0;
}

