#include "Box.h"

Box::Box() : _value(0) { _objects++; }
Box::Box(int v) : _value(v) { _objects++; }
Box::Box(const Box& other) : _value(other._value) { _objects++; }
Box::~Box() { _value = 666; _objects--; }
Box& Box::operator=(const Box& other) { _value = other._value;  return *this; }
int Box::value() const { return _value; }
void Box::inc() { _value++; }
int Box::objects() { return _objects; }

int Box::_objects;

