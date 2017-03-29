#include "Box.h"

Box::Box() : _value(0) { _objects++; refcount = 0; }
Box::Box(int v) : _value(v) { _objects++; refcount = 0; }
Box::Box(const Box& other) : _value(other._value) { _objects++; refcount = 0; }
Box::~Box() { _value = 666; _objects--; }
int Box::value() const { return _value; }
int Box::objects() { return _objects; }

int Box::_objects;
