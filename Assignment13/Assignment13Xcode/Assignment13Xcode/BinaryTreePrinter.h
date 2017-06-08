/**
 * Printer for a binary tree of up to height 5.
 * T must be a type that supports the << operation.
 *
 * Author: Ron Mak
 *         Department of Computer Engineering
 *         San Jose State University
 */
#ifndef BINARY_TREE_PRINTER_H
#define BINARY_TREE_PRINTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include "BinaryNode.h"
#include "BinarySearchTree.h"

using namespace std;

template <class T>
class BinaryTreePrinter
{
public:
    static const int MAX_HEIGHT = 5;  // cannot print trees > MAX_HEIGHT

private:
    static const int MAX_LEVELS = MAX_HEIGHT + 1;
    static const int POWERS_OF_2[];

public:
    BinaryTreePrinter(BinarySearchTree<T>& tree);
    virtual ~BinaryTreePrinter();

    void print();

private:
    BinarySearchTree<T>& tree;  // the tree to print

    void printData(int level, int offset,
                   BinaryNode<T> *levelNodes[]);
    void printOutgoingPointers(int level, int offset,
                               BinaryNode<T> *levelNodes[]);
    void printConnectingDashes(int level, int offset,
                               BinaryNode<T> *levelNodes[]);
    void printIncomingPointers(int level, int offset,
                               BinaryNode<T> *levelNodes[]);
    void nextLevel(int level, BinaryNode<T> *levelNodes[]);
    void printSpaces(int count);
    void printDashes(int count);
};

template <class T>
const int BinaryTreePrinter<T>::POWERS_OF_2[] = {1, 2, 4, 8, 16, 32, 64, 128};

/**
 * Constructor.
 * @param tree the tree to print.
 */
template <class T>
BinaryTreePrinter<T>::BinaryTreePrinter(BinarySearchTree<T>& tree)
    : tree(tree)
{
}

/**
 * Destructor.
 */
template <class T>
BinaryTreePrinter<T>::~BinaryTreePrinter()
{
}

/**
 * Print the tree using a level-order traversal.
 */
template <class T>
void BinaryTreePrinter<T>::print()
{
    // Queue of nodes at this level.
    BinaryNode<T> *thisLevelNodes[32];

    int height = tree.height();
    int offset = POWERS_OF_2[(height+1)]-1;

    thisLevelNodes[0] = tree.getRoot();

    // Loop to print each level of nodes.
    for (int level = 0; level <= height; level++)
    {
        if (level > MAX_LEVELS)
        {
            cout << "*** Too many levels to print. ***\n";
            break;
        }

        // Print node data.
        printData(level, offset, thisLevelNodes);

        if (level != height)
        {
            // Print outgoing pointers /\ from each parent node->
            printOutgoingPointers(level, offset, thisLevelNodes);

            offset = POWERS_OF_2[height - level] - 1;

            // Print connecting dashes ----
            if (level < height-1)
            {
                printConnectingDashes(level, offset, thisLevelNodes);
            }

            // Print incoming pointers / and \ to each child node->
            printIncomingPointers(level, offset, thisLevelNodes);

            // Prepare the next level of nodes.
            nextLevel(level, thisLevelNodes);
        }
    }
}

/**
 * Print node data.
 * @param level the current level
 * @param offset the current offset
 * @param levelNodes the current level of nodes
 */
template <class T>
void BinaryTreePrinter<T>::printData(int level, int offset,
                                     BinaryNode<T> *levelNodes[])
{
    printSpaces(offset);

    int k = POWERS_OF_2[level];
    for (int i = 0; i < k; i++)
    {
        BinaryNode<T> *ptr = levelNodes[i];

        if (ptr != nullptr)
        {
            cout << setw(3) << ptr->data << " ";
        }
        else
        {
            cout << "    ";
        }

        // Space over to the next node in this level.
        if (i < k-1) printSpaces(2*offset - 2);
    }

    cout << endl;
}

/**
 * Print outgoing pointers /\ from each non-null parent node->
 * @param level the current level
 * @param offset the current offset
 * @param levelNodes the current level of nodes
 */
template <class T>
void BinaryTreePrinter<T>::printOutgoingPointers(int level, int offset,
                                                 BinaryNode<T> *levelNodes[])
{
    printSpaces(offset);

    int k = POWERS_OF_2[level];
    for (int i = 0; i < k; i++)
    {
        BinaryNode<T> *ptr = levelNodes[i];

        // Has left child: print / forward slash
        if ((ptr != nullptr) && (ptr->left != nullptr))
        {
            cout << " /";
        }

        // No left child: print space
        else
        {
            cout << "  ";
        }

        // Has right child: print \ backward slash
        if ((ptr != nullptr) && (ptr->right != nullptr))
        {
            cout << "\\ ";
        }

        // No right child: print space
        else
        {
            cout << "  ";
        }

        // Space over to the next node in this level.
        if (i < k-1) printSpaces(2*offset-2);
    }

    cout << endl;
}

/**
 * Print the connecting dashes between
 * an outgoing pointer and an incoming pointer.
 * @param level the current level
 * @param offset the current offset
 * @param levelNodes the current level of nodes
 */
template <class T>
void BinaryTreePrinter<T>::printConnectingDashes(int level, int offset,
                                                 BinaryNode<T> *levelNodes[])
{
    if (offset > 1) printSpaces(offset);

    int k = POWERS_OF_2[level];
    for (int i = 0; i < k; i++)
    {
        BinaryNode<T> *ptr = levelNodes[i];

        // Has left child: print dashes
        if ((ptr != nullptr) && (ptr->left != nullptr))
        {
            printSpaces(3);
            printDashes(offset-1);
        }

        // No left child: print spaces
        else
        {
            printSpaces(offset+2);
        }

        // Has right child: print dashes
        if ((ptr != nullptr) && (ptr->right != nullptr))
        {
            printSpaces(2);
            printDashes(offset-1);
        }

        // No right child: print spaces
        else
        {
            printSpaces(offset+1);
        }

        // Space over to the next node in this level.
        if (i < k-1) printSpaces(2*offset+1);
    }

    cout << endl;
}

/**
 * Print incoming pointers / or \ to each non-null child node->
 * @param level the current level
 * @param offset the current offset
 * @param levelNodes the current level of nodes
 */
template <class T>
void BinaryTreePrinter<T>::printIncomingPointers(int level, int offset,
                                                 BinaryNode<T> *levelNodes[])
{
    printSpaces(offset);

    int k = POWERS_OF_2[level];
    for (int i = 0; i < k; i++)
    {
        BinaryNode<T> *ptr = levelNodes[i];

        // Left child: print /
        if ((ptr != nullptr) && (ptr->left != nullptr))
        {
            cout <<"  /";
        }

        // No left child: print spaces
        else
        {
            printSpaces(3);
        }

        // Right child: print \ backward slash
        if ((ptr != nullptr) && (ptr->right != nullptr))
        {
            printSpaces(2*offset);
            cout << "\\";
        }

        // No right child: print spaces
        else
        {
            printSpaces(2*offset+1);
        }

        // Space over to the next node in this level.
        if (i < k-1) printSpaces(2*offset);
    }

    cout << endl;
}

/**
 * Prepare the next level of nodes.
 * @param level the current level
 * @param levelNodes the current level of nodes
 * @return the next level of nodes.
 */
template <class T>
void BinaryTreePrinter<T>::nextLevel(int level, BinaryNode<T> *levelNodes[])
{
    int size = POWERS_OF_2[level+1];
    BinaryNode<T> *nextLevel[size];

    for (int i = 0; i < POWERS_OF_2[level]; i++)
    {
        BinaryNode<T> *ptr = levelNodes[i];

        // Queue the left child nodes of each non-null parent node->
        nextLevel[2*i] = (ptr != nullptr) && (ptr->left != nullptr)
                       ? ptr->left : nullptr;

        // Queue the right child nodes of each non-null parent node->
        nextLevel[2*i+1] = (ptr != nullptr) && (ptr->right != nullptr)
                         ? ptr->right : nullptr;
    }

    for (int i = 0; i < size; i++) levelNodes[i] = nextLevel[i];
}

/**
 * Print spaces.
 * @param count the number of spaces.
 */
template <class T>
void BinaryTreePrinter<T>::printSpaces(int count)
{
    for (int i = 0; i < count; i++) cout << " ";
}

/**
 * Print dashes.
 * @param count the number of dashes.
 */
template <class T>
void BinaryTreePrinter<T>::printDashes(int count)
{
    for (int i = 0; i < count; i++) cout << "-";
}

#endif // BINARY_TREE_PRINTER_H