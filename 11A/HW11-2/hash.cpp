#include <vector>

#include "hash.hpp"

using namespace std;

int hashCode(int x, int n)
{
    if (x >= 0) return x % n; else return -x % n;
}

/**
 Implement the algorithm for finding an element in a hash table
 with linear probing. The probing sequence simply visits
 
 h, h + 1, h + 2, ...,
 
 reduced modulo the table size n.
 
 For simplicity, you store integers in the table. Use the given
 hashCode function for hashing them.
 
 To make sure that you only follow the probing sequence and don't
 search the entire table, you return a count of the number of visited
 entries. If the element was not found, return the negative of
 that count. Run the program once to see what you are expected to do.
 */

int find(const vector<int>& table, int element)
{
    int h = hashCode(element, table.size());
    int visited = 0;
    while (visited < table.size()) {
        visited++;
        h %= table.size();
        if (table.at(h) == EMPTY) {
            break;
        }else if (table.at(h) == element ) {
            return visited;
        }
        h++;
    }
    // Not found
    return -visited;
}

