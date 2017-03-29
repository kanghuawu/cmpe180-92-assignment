
#include <algorithm>
#include <sstream>

using namespace std;

/*
 Override the & and + operators!
 */

#include "interval.h"

Interval::Interval()
{
    xmin = 0;
    xmax = 0;
}

Interval::Interval(int xmin, int xmax)
{
    this->xmin = xmin;
    this->xmax = xmax;
}

bool Interval::isEmpty() const
{
    return xmin >= xmax;
}

string Interval::toString() const
{
    stringstream sout;
    sout << "[" << xmin << ", " << xmax << ")";
    return sout.str();
}

Interval operator+(const Interval& a, const Interval& b)
{
    Interval plus;
    if (a.isEmpty())
    {
        return b;
    }else if (b.isEmpty())
    {
        return a;
    }else if (max(a.xmin, b.xmin) - min(a.xmax, b.xmax) >= -1) {
        plus.xmin = min(a.xmin, b.xmin);
        plus.xmax = max(a.xmax, b.xmax);
    }else{
        plus.xmax = 0;
        plus.xmin = 0;
    }
    
    return plus;
}

Interval operator&(const Interval& a, const Interval& b)
{
    Interval c(max(a.xmin, b.xmin), min(a.xmax, b.xmax));
    if (c.isEmpty()) {
        Interval c(0,0);
        return c;
    }
    return c;
}
