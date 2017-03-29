#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
}

SortedVector::~SortedVector()
{
}

/***** Complete this file. *****/

void SortedVector::prepend(int value)
{
    data.insert(data.begin(), value);
}

void SortedVector::append(int value)
{
    data.push_back(value);
}

bool SortedVector::find(int value) const
{
    for(vector<int>::const_iterator it = data.begin() ; it != data.end(); ++it)
        if (*it == value) return true;
    
    return false;
}

int SortedVector::get_value(int i) const
{
    return data.at(i);
}

void SortedVector::clear()
{
    vector<int>::iterator it = data.begin();
    while (!data.empty())
    {
        it = data.erase(it);
    }
}

bool SortedVector::check()
{
    if (data.size() == 0) return true;
    
    vector<int>::iterator it = data.begin();
    int prev = *it;
    while ((++it != data.end()) && (prev <= *it));
    return it == data.end();
}



