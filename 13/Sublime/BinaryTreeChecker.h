/**
 * A binary tree checker for those of us who are paranoid
 * about getting binary trees correct. It maintains a running
 * copy of a tree's node data in set elements. A tree node
 * deletion has a corresponding set element deletion. The tree
 * node data is compared to the set elements. Both the tree node
 * data and the set elements can be printed to verify they match.
 *
 * Comparable must be a type that supports comparisons
 * using the relational operators.
 *
 * Author: Ron Mak
 *         Department of Computer Engineering
 *         San Jose State University
 */
#ifndef BINARY_TREE_CHECKER_H
#define BINARY_TREE_CHECKER_H

#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
#include "BinaryNode.h"
#include "BinarySearchTree.h"
using namespace std;

template <typename Comparable>
class BinaryTreeChecker
{
public:
    static const int NO_ERROR          =  0;
    static const int DATA_MISMATCH     = -1;
    static const int INSUFFICIENT_DATA = -2;
    static const int REMAINING_DATA    = -3;

    BinaryTreeChecker(BinarySearchTree<Comparable>& tree);
    virtual ~BinaryTreeChecker();

    void clear();
    void add(const Comparable data);
    void remove(const Comparable data);
    int check(bool dump);

private:
    BinarySearchTree<Comparable>& tree;        // the tree to check
    set<Comparable, less<Comparable> > cache;  // the cache of data items
    set<Comparable, less<Comparable> > data;   // the tree's data items

    void walk(BinaryNode<Comparable> *node);
    int compare(bool dump);
};

/**
 * Default constructor.
 */
template <typename Comparable>
BinaryTreeChecker<Comparable>::BinaryTreeChecker(BinarySearchTree<Comparable>& tree)
    : tree(tree)
{
    cache.clear();
}

/**
 * Destructor.
 */
template <typename Comparable>
BinaryTreeChecker<Comparable>::~BinaryTreeChecker()
{
}

/**
 * Clear the cache.
 */
template <typename Comparable>
void BinaryTreeChecker<Comparable>::clear()
{
    cache.clear();
}

/**
 * Add a tree node's data item to the cache.
 * @param data the data item to add.
 */
template <typename Comparable>
void BinaryTreeChecker<Comparable>::add(const Comparable data)
{
    cache.insert(data);
}

/**
 * Remove a data item from the cache.
 * @param data the data item to remove.
 */
template <typename Comparable>
void BinaryTreeChecker<Comparable>::remove(const Comparable data)
{
    cache.erase(data);
}

/**
 * Check the tree's current data items against the cache.
 * @param dump true to dump the data items in the tree and in the cache.
 * @return a status code.
 */
template <typename Comparable>
int BinaryTreeChecker<Comparable>::check(bool dump)
{
    data.clear();
    walk(tree.getRoot());

    return compare(dump);
}

/**
 * Do an inorder walk of the tree to collect its data items.
 * @param node the root node of the subtree to walk (initially the tree root).
 */
template <typename Comparable>
void BinaryTreeChecker<Comparable>::walk(BinaryNode<Comparable> *node)
{
    if (node == nullptr) return;

    walk(node->left);
    data.insert(node->data);
    walk(node->right);
}

/**
 * Compare the tree's data items against the data items in the cache.
 * @return a status code.
 */
template <typename Comparable>
int BinaryTreeChecker<Comparable>::compare(bool dump)
{
    typename set<Comparable, less<Comparable> >::iterator itCache;
    typename set<Comparable, less<Comparable> >::iterator itData;

    itCache = cache.begin();
    itData  = data.begin();

    if (dump) cout << endl;

    while (itCache != cache.end())
    {
        if (itData == data.end()) return INSUFFICIENT_DATA;
        if (dump) cout << *itData << ":" << *itCache << " ";
        if (*itCache != *itData) return DATA_MISMATCH;

        itCache++;
        itData++;
    }

    if (dump) cout << endl;
    if (itData != data.end()) return REMAINING_DATA;

    return NO_ERROR;
}

#endif // BINARY_TREE_CHECKER_H