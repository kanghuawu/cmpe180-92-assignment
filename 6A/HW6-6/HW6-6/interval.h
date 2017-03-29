#include <string>

using namespace std;

/*
 A half-open interval [a, b) = { x | a <= x < b }
 */
class Interval
{
public:
    /**
     Constructs An empty interval.
     */
    Interval();
    /**
     Constructs an interval [xmin, xmax)
     */
    Interval(int xmin, int xmax);
    
    /**
     Checks if this interval is empty.
     */
    bool isEmpty() const;
    
    /**
     Yields a string representation of this interval.
     */
    string toString() const;
    
    
    /**
     The intersection of a and b. If the intersection is empty,
     return [0, 0).
     */
    friend Interval operator&(const Interval& a, const Interval& b);
    
    /**
     The smallest interval holding both a and b. (Not the union--that
     might not be an interval.)
     If a or b is empty, return the other.
     */
    friend Interval operator+(const Interval& a, const Interval& b);
private:
    int xmin;
    int xmax;
};

