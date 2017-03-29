//SOLUTION

#include "path.h"

/*
 Write the constructor.
 Dynamically allocate an array to hold the x- and y-values!
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

