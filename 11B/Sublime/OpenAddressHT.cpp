#include <iostream>
#include <iomanip>
#include "OpenAddressHT.h"
#include "HashEntry.h"

using namespace std;

/**
 * Default constructor
 */
OpenAddressHT::OpenAddressHT() : HashTable() {}

/**
 * Constructor. Initialize each table slot to nullptr.
 */
OpenAddressHT::OpenAddressHT(int size) : HashTable(size)
{
    for(int i = 0; i < size; i++) table.at(i) = nullptr;
}

/**
 * Destructor. Delete all the entries in the table.
 */
OpenAddressHT::~OpenAddressHT()
{
    for(int i = 0; i < size; i++) delete table.at(i);
}

/**
 * Return an entry at a given index of the hash table.
 * @param index the index.
 * @return the entry.
 */
HashEntry *OpenAddressHT::get_entry(const int index) const
{
    return table.at(index);
}

/**
 * Search for a given table entry. Count the number of probes.
 * @param key the key of the entry to find.
 * @param probe_count the cumulative count of probes.
 * @return the hash table index of the entry if found, else of an empty slot.
 */
int OpenAddressHT::search(const string& key, int& probe_count)
{
    /***** Complete this member function. *****/
    
    // Initial probe index.
    int index = hash(key) % size;
    while(key != table.at(index)->word || table.at(index) == nullptr){
        index = next_index(index);
        probe_count++;
    }
    return index;  // of the found entry or of an empty slot
}

/**
 * If an entry isn't already in the table, enter it with a
 * frequency count of 1. If the entry already exists,
 * update it by incrementing its frequency count by 1.
 * Count the number of probes from the initial search.
 * @param key the key of the entry to enter or update.
 * @return the index of the newly entered or updated entry.
 */
int OpenAddressHT::enter(const string& key, int& probe_count)
{
    // Search for the entry key.
    int index = search(key, probe_count);
    if(table.at(index) == nullptr){
        table.at(index)->word = key;
        table.at(index)->count = 1;
    }else{
        table.at(index)->count++;
    }
    return index;
}

/**
 * Print the contents of the hash table.
 * Skip empty table slots.
 */
void OpenAddressHT::dump() const
{
    for (int i = 0; i < size; i++){
        if (table.at(i) != nullptr)
        {
            cout << setw(5) << i << ":" << setw(4) << table.at(i)->count << "-"<< table.at(i)->word;
        }
    }
}
