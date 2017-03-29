#include <iostream>
using namespace std;

/**
 In this implementation of the Pair class, you will NOT COPY
 Box objects. Instead, when copying Pair objects, copy the pointers
 and increment the refcount of the box whose pointer you copied,
 so that the refcount always tells you how many pointers point
 to it. If the refcount goes to zero, delete the Box object.
 
 Note that the Pair(int v1, int v2) constructor also shares
 the Box object if v1 equals v2.
 */

#include "Pair.h"

Pair::Pair(int v1, int v2)
{
    first = new Box(v1);
    if (v1 == v2)
        second = first;
    else
        second = new Box(v2);
    first->refcount++;
    second->refcount++;
}

Pair::Pair(const Pair& other)
{
    cout << "test" << endl;
    first = other.first;
    first->refcount++;
    second = other.second;
    second->refcount++;
}

Pair& Pair::operator=(const Pair& other)
{
    if(this != &other){
        first->refcount--;
        if(first->refcount == 0){
            first->~Box();
        }
        second->refcount--;
        if(second->refcount == 0){
            second->~Box();
        }
        first = other.first;
        first->refcount++;
        second = other.second;
        second->refcount++;
    }
    return *this;
}


Pair::~Pair()
{
    first->refcount--;
    if(first->refcount == 0){
        first->~Box();
        delete first;
    }
    second->refcount--;
    if(second->refcount == 0){
        first->~Box();
        delete second;
    }
}

