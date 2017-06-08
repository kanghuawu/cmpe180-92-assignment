#ifndef SORTEDLIST_H_
#define SORTEDLIST_H_

#include <list>
using namespace std;

class SortedList
{
public:
    SortedList();
    virtual ~SortedList();
    
    void prepend(int value);
    void append(int value);
    bool find(int value) const;
    int get_value(int i) const;
    void clear();
    bool check();
    
private:
    list<int> data;
};

#endif /* SORTEDLIST_H_ */
