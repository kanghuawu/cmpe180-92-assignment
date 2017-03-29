
#include "SleepyBug.h"

void SleepyBug::move(int dx){
    if(moves < 3){
        Bug::move(dx);
        moves++;
    }else{
        moves = 0;
    }
}
