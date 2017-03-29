#ifndef BUGPARADE_H
#define BUGPARADE_H

#include <vector>
#include "Bug.h"

using namespace std;

/**
 A parade of bugs that moves together.
 */
class BugParade
{
public:
    /**
     Adds a bug to the parade.
     */
    void add(Bug* bug);
    /**
     Moves all bugs by the given distance.
     */
    vector<int> moveAll(int distance);
private:
    vector<Bug*> bugs;
};
#endif

