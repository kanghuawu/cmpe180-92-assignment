#include <iostream>
using namespace std;

int main()
{
    cout << "Hours: ";
    int hours;
    cin >> hours;
    cout << "Minutes: ";
    int minutes;
    cin >> minutes;
    cout << "Minutes to add: ";
    int minutesToAdd;
    cin >> minutesToAdd;
    
    // Add minutesToAdd minutes to the given hours/minutes
    // and normalize hours/minutes to military time (so that
    // hours is between 0 and 23 and minutes between 0 and 59)
    int hoursToAdd = (minutes + minutesToAdd)/60;

    if (minutes+minutesToAdd >= 60) {
        minutes = (minutes+minutesToAdd)%60;
        hours = hours+hoursToAdd;
        hours %= 24;
    }else if (minutes+minutesToAdd < 0){
        minutes = 60+(minutes+minutesToAdd)%60;
        hours = hours + hoursToAdd - 1;
        if (hours < 0) {
            hours = 24 + hours%24;
        }
    }else{
        minutes = minutes+minutesToAdd;
    }
    
    cout << endl << "Result: " << hours << ":" << minutes << endl;
    return 0;
}

