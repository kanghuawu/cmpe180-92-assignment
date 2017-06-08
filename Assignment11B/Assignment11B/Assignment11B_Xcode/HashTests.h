#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <vector>
#include "HashEntry.h"
using namespace std;

/**
 * Abstract base class for open addressing
 * and chained hash tables.
 */
class HashTable
{
public:
    HashTable();
    HashTable(int size);
    virtual ~HashTable();
    
    int get_size() const;
    virtual void dump() const = 0;  // abstract: define in a subclass
    
protected:
    int size;
    
    int hash(const string& word) const;
    
private:
    int bad_hash_function(const string& word) const;
    int poor_hash_function(const string& word) const;
    int good_hash_function(const string& word) const;
};

#endif /* HASHTABLE_H_ */
