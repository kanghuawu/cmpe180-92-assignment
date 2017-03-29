#include "Bug.h"

Bug::Bug()
{
    x = 0;
}

int Bug::getPosition() const
{
    return x;
}

void Bug::move(int amount)
{
    x = x + amount;
}

