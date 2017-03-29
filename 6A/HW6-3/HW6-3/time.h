#include <iostream>

using namespace std;

class Time
{
public:
    /**
     Constructs a time with the given hours (0...23) and minutes
     (0...59)
     */
    Time(int hours, int minutes);
    int getHours();
    int getMinutes();
    
    /**
     Sends this time in hh:mm format to the given output stream.
     Returns out for chaining.
     */
    friend ostream& operator<<(ostream& out, Time t);
    
private:
    int minutesSinceMidnight;
};

