#include "hash.hpp"

int hashCode(int x, int n)
{
    if (x >= 0) return x % n; else return -x % n;
}

/**
 Implement the algorithm for inserting an element in a hash table
 with linear probing. The probing sequence simply visits
 
 h, h + 1, h + 2, ...,
 
 reduced modulo the table size n.
 
 If the element is present or the table is full, do not modify the table.
 
 For simplicity, you store integers in the table. Use the given
 hashCode function for hashing them.
 */

void insert(vector<int>& table, int element)
{
    int h = hashCode(element, table.size());
    int n = 0;
    while (n < table.size()) {
        h %= table.size();
        if (table.at(h) == EMPTY) {
            table.at(h) = element;
            break;
        }else if (table.at(h) == element) {
            break;
        }
        h++;
        n++;
    }
}

/**
 Implement an algorithm for removing an element from a hash table
 with linear probing. If the element is absent, do not modify the table.
 Your textbook has two options for implementing removal, neither of
 which is attractive. Instead, do the following: If you remove
 table[h], then visit the remainder of the probing sequence
 until you get EMPTY. Collect all elements that aren't at the natural
 position and replace them with EMPTY. Then insert them again.
 */

void remove(vector<int>& table, int element)
{
    int h = hashCode(element, table.size());
    vector<int> restore_num;
    int index = h;
    while (index < table.size() && table.at(index) != EMPTY) {
        index %= table.size();
        if (table.at(index) == element) {
            table.at(index) = EMPTY;
        }else {
            restore_num.push_back(table.at(index));
            table.at(index) = EMPTY;
        }
        index++;
    }
    for (int i = 0; i < restore_num.size(); i++) {
        insert(table, restore_num.at(i));
    }
}
