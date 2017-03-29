
#include <cmath>

#include "point.h"

Point::Point(double xvalue, double yvalue)
{
    x = xvalue;
    y = yvalue;
}

double Point::get_x() { return x; }
double Point::get_y() { return y; }

/**
 Compute the distance between this point and another point.
 @param other the other point
 @return the distance between them.
 */

double Point::distance(Point other)
{
    return sqrt(pow(get_x()-other.get_x(),2)+pow(get_y()-other.get_y(),2));
}

/**
 Compute the midpoint between this point and another point.
 @param other the other point
 @return the point halfway between them.
 */

Point Point::midpoint(Point other)
{
    Point c((get_x()+other.get_x())/2, (get_y()+other.get_y())/2);
    return c;
}

