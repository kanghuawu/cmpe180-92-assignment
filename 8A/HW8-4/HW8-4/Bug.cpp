#include "Bug.h"

Bug::Bug(int initialX)
{
    x = initialX;
}

int Bug::getPosition() const
{
    return x;
}

void Bug::move(int amount)
{
    x = x + amount;
}

