#include <iostream>
using namespace std;

/**
 Implement the constructor to initialize two Box values,
 and do the right thing in the "big 3".
 
 Note that the Box::show method prints a count of ALL Box
 objects that have been created and not yet destroyed.
 */

#include "Pair.h"

Pair::Pair(int v1, int v2) {
    first = new Box(v1);
    second = new Box(v2);
}

// copy constructorbox
Pair::Pair(const Pair &other) {
    first = new Box(other.first->value());
    second = new Box(other.second->value());
}

// operator=
Pair &Pair::operator=(const Pair &other) {
    if(&other != this) { // prevent error from x = x (self assignment)
        delete first;
        delete second;
        first = new Box(other.first->value());
        second = new Box(other.second->value());
    }
    return *this;
}

// destructor
Pair::~Pair() {
    delete first;
    delete second;
}
