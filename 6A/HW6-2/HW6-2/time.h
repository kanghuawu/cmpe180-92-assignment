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
     Yields the difference between time a and b in minutes
     */
    friend int operator-(Time a, Time b);
private:
    int minutesSinceMidnight;
};

