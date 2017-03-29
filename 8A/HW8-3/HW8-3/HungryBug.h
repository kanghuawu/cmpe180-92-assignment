#ifndef HUNGRYBUG_H
#define HUNGRYBUG_H
#include "Bug.h"
/**
 A HungryBug moves as fast as a regular bug. But it needs to eat
 one unit of food for each call to move, or it won't move.
 */
class HungryBug : public Bug
{
public:
    HungryBug(int initialFoodUnits);
    void eat(int foodUnits);
    virtual void move(int dx);
private:
    int food;
};
#endif

