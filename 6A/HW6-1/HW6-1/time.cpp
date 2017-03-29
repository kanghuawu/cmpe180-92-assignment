/*
 Implement the - operator as a member function!
 */

#include "time.h"

Time::Time(int hours, int minutes)
{
    minutesSinceMidnight = hours * 60 + minutes;
}

int Time::getHours()
{
    return minutesSinceMidnight / 60;
}

int Time::getMinutes()
{
    return minutesSinceMidnight % 60;
}

int Time::operator-(Time other)
{
    return minutesSinceMidnight-other.minutesSinceMidnight;
}
