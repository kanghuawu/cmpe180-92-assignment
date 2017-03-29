class Path
{
public:
    /**
     Constructs a path of points (x0, y0), (x1, y1), (x2, y2),
     ... of length n. Initially, all coordinates are zero.
     */
    Path(int n);
    
    /**
     Gets the ith x-coordinate.
     */
    int getX(int i);
    /**
     Gets the ith y-coordinate.
     */
    int getY(int i);
    
    /**
     Sets the ith point to the given x- and y-coordinate.
     */
    void set(int i, int x, int y);
    
    /**
     Gets the number of points in this path.
     */
    int getLength();
    
    Path& operator=(const Path& rhs);
    
private:
    int* xy;
    int length;
};

