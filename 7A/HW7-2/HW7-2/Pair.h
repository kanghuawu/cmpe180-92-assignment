#ifndef PAIR_H
#define PAIR_H

#include <iostream>

#include "Box.h"

class Pair
{
public:
    Pair(int v1, int v2);
    Pair(const Pair& other);
    Pair& operator=(const Pair& other);
    ~Pair();
    
    void show() const { std::cout << "(" << first->value() << ", " << second->value() << ") " << Box::objects() << " boxes" << std::endl; }
    void inc() { first-> inc(); second-> inc(); }
private:
    Box* first;
    Box* second;
};

#endif

