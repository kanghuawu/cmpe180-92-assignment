#ifndef CHAINEDHT_H_
#define CHAINEDHT_H_

#include <vector>
#include "HashTable.h"
#include "HashNode.h"
using namespace std;

/**
 * Class for hash tables that use collision chains.
 */
class ChainedHT : public HashTable
{
public:
    ChainedHT();
    ChainedHT(int size);
    virtual ~ChainedHT();
    
    HashEntry *search(const string& word, int& probe_count);
    HashEntry *enter(const string& word, int& probe_count);
    
    void dump() const;
    double avg_chain_length() const;
    
private:
    vector<HashNode*> table;  // hash table of chain head pointers
};
#endif /* CHAINEDHT_H_ */
