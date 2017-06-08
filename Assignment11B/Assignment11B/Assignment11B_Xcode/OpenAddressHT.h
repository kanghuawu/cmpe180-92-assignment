#ifndef OPENADDRESSHT_H_
#define OPENADDRESSHT_H_

#include "HashTable.h"
using namespace std;

/**
 * Abstract base class for open addressing hash tables.
 */
class OpenAddressHT: public HashTable
{
public:
    OpenAddressHT();
    OpenAddressHT(int size);
    virtual ~OpenAddressHT();
    
    HashEntry *get_entry(const int index) const;
    virtual int search(const string& word, int& probe_count);
    virtual int enter(const string& word, int& probe_count);
    
    void dump() const;
    
protected:
    virtual int next_index(int index) = 0;  // abstract: define in a subclass
    
private:
    vector<HashEntry*> table;  // the hash table of pointers to entries
};

#endif /* OPENADDRESSHT_H_ */
