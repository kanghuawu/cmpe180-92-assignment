#include "time.h"

/**
 Implement operator- as a non-member!
 */


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

int operator-(Time a, Time b)
{
    return a.minutesSinceMidnight-b.minutesSinceMidnight;
}

