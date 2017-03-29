/*
 Look at QuickBug.h and then complete the implementation.
 */
#include "QuickBug.h"

void QuickBug::move(int dx)
{
    Bug::move(dx * 2);
}
