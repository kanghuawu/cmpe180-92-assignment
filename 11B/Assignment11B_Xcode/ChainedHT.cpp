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
    for(int i = 0; i < size; i++) table.push_back(nullptr);
}

/**
 * Destructor. Delete all the entries in the collision chains.
 */
ChainedHT::~ChainedHT()
{
    for(int i = 0; i < size; i++){
        HashNode *findnode = table.at(i);
        while (findnode != nullptr) {
            findnode->~HashNode();
            findnode = findnode->next;
        }
    }
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
    while(true){
        probe_count++;
        if(findnode == nullptr || findnode->entry->word == word) break;
        findnode = findnode->next;
    }
    return findnode == nullptr ? nullptr : findnode->entry;
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
    int index = hash(word);
    if(entry_ptr == nullptr){
        HashEntry *entry_ptr = new HashEntry(word);
        HashNode *newnode = new HashNode(entry_ptr);
        if(table.at(index) == nullptr){
            table.at(index) = newnode;
        }else{
            HashNode *temp = table.at(index);
            table.at(index) = newnode;
            newnode->next = temp;
        }
        probe_count--;
    // adding node at node end
//    if (entry_ptr == nullptr)
//    {
//        HashEntry *entry_ptr = new HashEntry(word);
//        HashNode *newnode = new HashNode(entry_ptr);
//        int index = hash(word);
//        if(table.at(index) == nullptr){
//            table.at(index) = newnode;
//            probe_count++;
//        }else{
//            HashNode *findnode = table.at(index);
//            while (findnode->next != nullptr) {
//                findnode = findnode->next;
//                probe_count++;
//            }
//            findnode->next = newnode;
//        }
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
        if (findnode != nullptr) {
            cout << setw(5) << i << ":" << endl;
            while (findnode != nullptr) {
                cout << setw(9) << findnode->entry->count << "-" << findnode->entry->word << endl;
                findnode = findnode->next;
            }
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

