#ifndef HASHENTRY_H_
#define HASHENTRY_H_

#include <string>
using namespace std;

/**
 * An entry for a hash table.
 */
class HashEntry
{
public:
    HashEntry() : word(""), count(0) {}
    HashEntry(string word) : word(word), count(1) {}
    
    string word;  // a word, used as the key
    int count;    // frequency count of the word, initially 1
};

#endif /* HASHENTRY_H_ */
