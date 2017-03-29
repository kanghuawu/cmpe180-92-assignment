#ifndef HASHNODE_H_
#define HASHNODE_H_

#include "HashEntry.h"

/**
 * A node of a collision chain.
 */
class HashNode
{
public:
    HashNode() : next(nullptr), entry(nullptr) {}
    HashNode(HashEntry *entry) : next(nullptr), entry(entry) {}
    
    ~HashNode() { delete entry; }
    
    HashNode  *next;   // pointer to the next node of the chain
    HashEntry *entry;  // pointer to the node's data (a hash entry)
};


#endif /* HASHNODE_H_ */
