#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Person.h"
using namespace std;

/***** Write the constructors. *****/
Person::Person(int level, string name) : level(level), name(name){}

Person::Person(int level, string name, string spouse) : level(level), name(name), spouse_name(spouse){}

/**
 * Destructor
 */
Person::~Person()
{
    for (Person *child : children) {
        if(child->children.empty())
            delete child;
        else
            child->~Person();
    }
}

/**
 * Have a child.
 * @param child pointer to the new child.
 */
void Person::have_child(Person *child)
{
    children.push_back(child);
    child->parent = this;
}

/**
 * Print a person.
 */
void Person::print() const
{
    cout << name;
    if (spouse_name != "")
        cout <<" (" << spouse_name << ")";
    cout << endl;
    for (int i = 0; i < children.size(); i++) {
        children[i]->print_bar();
    }
    
}

/**
 * Print the vertical bar.
 */
void Person::print_bar() const
{
//    cout << parent->children.back()->name;
    if (level > 1 && parent->parent->children.back() != parent){
        cout << string(4 * (level - 2),' ') << "|   |" << endl;
        cout << string(4 * (level - 2),' ') << "|   +---";
    }else{
        cout << string(4 * (level - 1),' ') << "|" << endl;
        cout << string(4 * (level - 1),' ') << "+---";
    }
    this->print();
}
