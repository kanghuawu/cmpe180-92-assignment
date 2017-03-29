#include <iostream>
#include <iomanip>
#include "ChainedHT.h"
using namespace std;

/**
 * Default constructor.
 */
ChainedHT::ChainedHT() : HashTable() {}

/**
 * Constructor. Initialize each table slot to nullptr.
 */
ChainedHT::ChainedHT(int size) : HashTable(size)
{
    for(int i = 0; i < size; i++) table.at(i) = nullptr;
}

/**
 * Destructor. Delete all the entries in the collision chains.
 */
ChainedHT::~ChainedHT()
{
    for(int i = 0; i < size; i++) delete table.at(i);
}

/**
 * Search for a given table entry. Count the number of probes.
 * @param key the key of the entry to find.
 * @param probe_count the cumulative count of probes.
 * @return a pointer to the entry if found, else return nullptr.
 */
HashEntry *ChainedHT::search(const string& word, int& probe_count)
{
    int index = hash(word);
    HashNode *findnode = table.at(index);
    while(findnode != nullptr || findnode->entry->word != word){
    	findnode = findnode->next;
    	probe_count++;
    }
    return findnode->entry;
}

/**
 * If an entry isn't already in the table, enter it with a
 * frequency count of 1. If the entry already exists,
 * update it by incrementing its frequency count by 1.
 * Count the number of probes from the initial search.
 * @param key the key of the entry to enter or update.
 * @return a pointer to the newly entered or updated entry.
 */
HashEntry *ChainedHT::enter(const string& word, int& probe_count)
{
    HashEntry *entry_ptr = search(word, probe_count);
    if (entry_ptr == nullptr)
    {
    	entry_ptr->word = word;
    	entry_ptr->count = 1;
    }else{
    	entry_ptr->count++;
    }
    return entry_ptr;
}

/**
 * Print the contents of the hash table.
 * Skip empty table slots.
 */
void ChainedHT::dump() const
{
    for (int i = 0; i < table.size(); i++)
    {
    	HashNode *findnode = table.at(i);
		cout << setw(5) << i << ":" << endl;
    	while(findnode != nullptr){
    		HashEntry *findentry = findnode->entry;
    		cout << setw(9) << findentry->count << "-" << findentry->word << endl;
    		findnode = findnode->next;
    	}
    }
}

/**
 * Compute the average chain length.
 */
double ChainedHT::avg_chain_length() const
{
	int len = 0;
    for (int i = 0; i < table.size(); i++)
    {
    	HashNode *findnode = table.at(i);
    	while(findnode != nullptr){
    		findnode = findnode->next;
    		len++;
    	}
    }
    return len / ((double)table.size());
}

