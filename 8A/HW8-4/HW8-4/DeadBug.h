#ifndef DEADBUG_H
#define DEADBUG_H

#include "Bug.h"

/**
 A bug that never moves.
 */
class DeadBug : public Bug
{
public:
    /**
     Constructs a dead bug with given initial position.
     */
    DeadBug(int initialX);
    
    /**
     Moves this bug by a given amount.
     @param amount the amount to move by
     */
    virtual void move(int amount);
};
#endif

