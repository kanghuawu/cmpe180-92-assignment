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
     Yields the difference between this time and other in minutes
     */
    int operator-(Time other);
private:
    int minutesSinceMidnight;
};

