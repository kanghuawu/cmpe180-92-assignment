
/*
 In the constructor, copy constructor, assignment operator, destructor
 print messages "Constructing ...", "Copying ...", "Assigning ... to ...", "Destroying ...", and do what else is necessary.
 */

#include <iostream>
#include "Trace.h"

using namespace std;

Trace::Trace(string s) : str(s) {
    cout << "Constructing " << str << endl;
}

Trace::Trace(const Trace& other) {
    cout << "Copying " << other.str << endl;
    //new Trace(other.str);
    str = other.str + "";
}

Trace& Trace::operator=(const Trace& other) {
    cout << "Assigning " << other.str << " to " << str << endl;
    if(this != &other){
        str = other.str;
    }
    return *this;
}

Trace::~Trace() {
    cout << "Destroying " << str << endl;
    str = "";
}

