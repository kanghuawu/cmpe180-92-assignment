#ifndef BUG_H
#define BUG_H
/**
 A bug that lives on a line and occupies integer positions.
 */
class Bug
{
public:
    /**
     Constructs a bug with given initial position.
     */
    Bug(int initialX);
    
    /**
     Gets the position of this bug.
     @return the position
     */
    virtual int getPosition() const;
    
    /**
     Moves this bug by a given amount.
     @param amount the amount to move by
     */
    virtual void move(int amount);
    
private:
    int x;
};
#endif

