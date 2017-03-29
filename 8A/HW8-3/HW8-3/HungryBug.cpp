
#include "HungryBug.h"

HungryBug::HungryBug(int initialFoodUnits) : food(initialFoodUnits){
    
}

void HungryBug::eat(int foodUnits){
    food += foodUnits;
}

void HungryBug::move(int dx){
    if(food > 0){
        Bug::move(dx);
        food--;
    }
}
