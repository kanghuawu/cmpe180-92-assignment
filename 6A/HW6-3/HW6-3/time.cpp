#include "time.h"

/*
 Implement the << operator!
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

ostream& operator<<(ostream& out, Time t)
{
    out.fill('0');
    out.width(2);
    out << t.getHours() << ":" ;
    out.fill('0');
    out.width(2);
    out << t.getMinutes();
    return out;
}
