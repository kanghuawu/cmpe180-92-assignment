#include <iostream>
using namespace std;
//SOLUTION

#include "path.h"

/*
 Implement the assignment operator!
 */

Path::Path(int n)
{
    length=n;
    xy = new int[2*length];
}

int Path::getX(int i)
{
    if (0 <= i && i < length)
        return xy[2 * i];
    else
        return 0;
}

int Path::getY(int i)
{
    if (0 <= i && i < length)
        return xy[2 * i + 1];
    else
        return 0;
}

void Path::set(int i, int x, int y)
{
    if (0 <= i && i < length)
    {
        xy[2 * i] = x;
        xy[2 * i + 1] = y;
    }
}

int Path::getLength()
{
    return length;
}

Path& Path::operator=(const Path& rhs)
{

    this -> length = rhs.length;
    for (int i = 0; i < length; i++) {
        set(i, rhs.xy[2 * i], rhs.xy[2 * i + 1]);
    }
    return *this;
}

