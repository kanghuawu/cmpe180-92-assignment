#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
}

SortedList::~SortedList()
{
}

/***** Complete this file. *****/

void SortedList::prepend(int value)
{
    data.insert(data.begin(), value);
}

void SortedList::append(int value)
{
    data.push_back(value);
}

bool SortedList::find(int value) const
{
    
    for(list<int>::const_iterator it = data.begin() ; it != data.end(); ++it)
        if (*it == value) return true;
    
    return false;
}

int SortedList::get_value(int i) const
{
    list<int>::const_iterator it;
    if (i < data.size() / 2) {
        list<int>::const_iterator it = data.begin();
        advance(it, i);
        return *it;
    }else
    {
        list<int>::const_reverse_iterator it = data.rbegin();
        advance(it, data.size() - i - 1);
        return *it;
    }
}

void SortedList::clear()
{
    list<int>::iterator it = data.begin();
    while (!data.empty())
    {
        it = data.erase(it);

    }
}

bool SortedList::check()
{
    if (data.size() == 0) return true;
    
    list<int>::iterator it = data.begin();
    int prev = *it;
    while ((++it != data.end()) && (prev <= *it));
    return it == data.end();
}
