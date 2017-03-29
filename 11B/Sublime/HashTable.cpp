
#include <iostream>
#include "HashTable.h"
#include "HashEntry.h"
using namespace std;

/**
 * Default constructor.
 */
HashTable::HashTable() : size(0) {}

/**
 * Constructor.
 * @param size the size of the hash table.
 */
HashTable::HashTable(int size) : size(size) {}

/**
 * Destructor.
 */
HashTable::~HashTable() {}

/**
 * @return the hash table size.
 */
int HashTable::get_size() const { return size; }

/**
 * The hash function.
 * You can experiment with different hash functions.
 * @param key the string key.
 * @return the mapped hash value.
 */
int HashTable::hash(const string& key) const
{
    return good_hash_function(key);
}

/**
 * The following examples of hash functions are based on
 * Data Structures and Algorithm Analysis in C++, 4th edition
 * by Mark Allen Weiss
 * Pearson, 2014
 * ISBN 978-0-13-284737-7
 */

/**
 * A bad hash function. Since the highest ASCII value is 127,
 * short key strings will only distribute to the low end of
 * a large hash table.
 * @param key the string key.
 * @return the mapped hash value.
 */
int HashTable::bad_hash_function(const string& key) const
{
    unsigned int hash = 0;
    
    for (int i = 0; i < key.length(); i++) hash += key[i];
    return hash%size;
}

/**
 * A poor hash function that uses factors 27 and 27-squared
 * on the first three characters of the key. But if the key strings
 * are English words, then there will be collisions among words
 * that start with the same three letters.
 * @param key the string key.
 * @return the mapped hash value.
 */
int HashTable::poor_hash_function(const string& key) const
{
    switch (key.length())
    {
        case 0:  return 0;
        case 1:  return key[0]%size;
        case 2:  return (key[0] + 27*key[1])%size;
        default: return (key[0] + 27*key[1] + 729*key[2])%size;
    }
}

/**
 * A good hash function that uses nested multiplication to compute
 * a polynomial function of 37 using all the key characters
 * to distribute over a large hash table.
 * @param key the string key.
 * @return the mapped hash value.
 */
int HashTable::good_hash_function(const string& key) const
{
    unsigned int hash = 0;
    
    for (int i = 0; i < key.length(); i++) hash += 37*hash + key[i];
    return hash%size;
}
