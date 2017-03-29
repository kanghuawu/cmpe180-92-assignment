class Point
{
public:
    Point(double xvalue, double yvalue);
    double get_x();
    double get_y();
    double distance(Point other);
    Point midpoint(Point other);
private:
    double x;
    double y;
};

