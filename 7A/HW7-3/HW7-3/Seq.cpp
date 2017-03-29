#include <iostream>
#include "Seq.h"

/*
 A Seq is a sequence of Box objects. The constructor Seq(int length)
 constructs a sequence of Box objects of the given length, all
 constructed with the default constructor. Implement that constructor
 and the "big 3" memory management functions.
 */

Seq::Seq(int length)
{
    len = length;
    boxes = new Box[len];
}

Seq::Seq(const Seq& other)
{
    len = other.len;
    boxes = new Box[len];
    for(int i = 0; i < len; i++){
        boxes[i] = other.boxes[i];
    }
}

Seq& Seq::operator=(const Seq& other)
{
    if(this != &other){
        delete []boxes;
        len = other.len;
        boxes = new Box[len];
        for (int i = 0; i < other.len; i++) {
            boxes[i] = other.boxes[i];
        }
        
    }
    return *this;
}

Seq::~Seq()
{
    delete []boxes;
}

