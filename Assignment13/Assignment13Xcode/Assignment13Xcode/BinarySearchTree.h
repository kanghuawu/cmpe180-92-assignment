/**
 * An implementation of the binary search tree and its operations.
 *
 * Comparable must be a type that supports comparisons
 * using the relational operators.
 */
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "BinaryNode.h"

template <typename Comparable>
class BinarySearchTree
{
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& rhs);
    virtual ~BinarySearchTree();

    //BinarySearchTree& operator=(const BinarySearchTree& rhs);

    BinaryNode<Comparable> *getRoot() const;
    int height();
    Comparable &findMin() const;
    Comparable &findMax() const;

    void clear();
    bool isEmpty() const;
    bool contains(const Comparable& data) const;
    void insert(const Comparable data);
    void remove(const Comparable& data);

protected:
    virtual int height(BinaryNode<Comparable> *ptr);
    virtual void insert(const Comparable& data, BinaryNode<Comparable>* &ptr);
    virtual void remove(const Comparable& data, BinaryNode<Comparable>* &ptr);

private:
    BinaryNode<Comparable> *root;

    BinaryNode<Comparable> *findMin(BinaryNode<Comparable> *ptr) const;
    BinaryNode<Comparable> *findMax(BinaryNode<Comparable> *ptr) const;
    void clear(BinaryNode<Comparable>* &ptr);
    bool contains(const Comparable& data, BinaryNode<Comparable> *ptr) const;
};

/**
 * Default constructor
 */
template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree() : root(nullptr)
{
}

/**
 * Copy constructor
 */
template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree& rhs)
    : root(clone(rhs->root))
{
}

/**
 * Destructor
 */
template <typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
    clear();
}

/**
 * Assignment operator
 */
/*
template <typename Comparable>
BinarySearchTree<Comparable>& BinarySearchTree<Comparable>::operator=(const BinarySearchTree& rhs)
{
    BinarySearchTree copy = rhs;
    std::swap(*this, copy);
    return *this;
}
*/

/**
 * @return pointer to the root of the tree.
 */
template <typename Comparable>
BinaryNode<Comparable> *BinarySearchTree<Comparable>::getRoot() const
{
    return root;
}

/**
 * Public method to return the height of a subtree.
 * @return the height.
 */
template <typename Comparable>
int BinarySearchTree<Comparable>::height()
{
    return height(root);
}

/**
 * Protected method to compute the height of a subtree.
 * @param ptr pointer to the root node of the subtree.
 * @return the height.
 */
template <typename Comparable>
int BinarySearchTree<Comparable>::height(BinaryNode<Comparable> *ptr)
{
    return ptr == nullptr ? -1
                           : 1 + max(height(ptr->left),
                                     height(ptr->right));
}

/**
 * Public method to find the minimum data item in a subtree.
 * @return the minimum data item in the tree
 *         or nullptr if the tree is empty.
 */
template <typename Comparable>
Comparable &BinarySearchTree<Comparable>::findMin() const
{
    if (isEmpty()) return nullptr;
    return findMin(root)->element;
}

/**
 * Private method to find the minimum data item in a subtree.
 * @param ptr pointer to the root node of the subtree.
 * @return pointer to the node containing the smallest data item
 *         or nullptr if the subtree is empty.
 */
template <typename Comparable>
BinaryNode<Comparable>
    *BinarySearchTree<Comparable>::findMin(BinaryNode<Comparable> *ptr) const
{
    if (ptr != nullptr)
    {
        while(ptr->left != nullptr) ptr = ptr->left;
    }

    return ptr;
}

/**
 * Public method to find the maximum data item in a subtree.
 * @return pointer to the maximum data item in the tree
 *         or nullptr if the tree is empty.
 */
template <typename Comparable>
Comparable &BinarySearchTree<Comparable>::findMax() const
{
    if (isEmpty()) return nullptr;
    return findMax(root)->element;
}

/**
 * Private method to find the maximum data item in a subtree.
 * @param ptr pointer to the root node of the subtree.
 * @return pointer to the node containing the largest data item
 *         or nullptr if the subtree is empty.
 */
template <typename Comparable>
BinaryNode<Comparable>
    *BinarySearchTree<Comparable>::findMax(BinaryNode<Comparable> *ptr) const
{
    if (ptr != nullptr)
    {
        while(ptr->right != nullptr) ptr = ptr->right;
    }

    return ptr;
}

/**
 * Public method to empty a subtree.
 */
template <typename Comparable>
void BinarySearchTree<Comparable>::clear()
{
    clear(root);
}

/**
 * Private method to empty a subtree.
 * @param ptr pointer to the root node of the subtree.
 */
template <typename Comparable>
void BinarySearchTree<Comparable>::clear(BinaryNode<Comparable>* &ptr)
{
    if (ptr != nullptr)
    {
        clear(ptr->left);
        clear(ptr->right);
        delete ptr;
        ptr = nullptr;
    }

}

/**
 * @return true if and only if the tree is empty.
 */
template <typename Comparable>
bool BinarySearchTree<Comparable>::isEmpty() const
{
    return root == nullptr;
}

/**
 * Public method to search for a data item in the tree.
 * @param data the data to search for.
 * @return true if and only if data is in the tree.
 */
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& data) const
{
    return contains(data, root);
}

/**
 * Private method to search for a data item in a subtree.
 * @param data the data to search for.
 * @param ptr pointer to the root node of the subtree.
 * @return true if and only if data is in the tree.
 */
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& data,
                                            BinaryNode<Comparable> *ptr) const
{
    while (ptr != nullptr)
    {
        if (data < ptr->data)
        {
            ptr = ptr->left;
        }
        else if (data > ptr->data)
        {
            ptr = ptr->right;
        }
        else
        {
            return true;  // found
        }
    }

    return false;         // not found
}

/**
 * Public method to insert a data item into a subtree
 * and set the new root of the subtree.
 * @param data the data to insert into the tree.
 */
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable data)
{
    insert(data, root);
}

/**
 * Protected method to insert a data item into a subtree
 * and set the new root of the subtree.
 * @param data the data to insert.
 * @param ptr pointer to the root node of the subtree.
 */
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable& data,
                                          BinaryNode<Comparable>* &ptr)
{
    if (ptr == nullptr)
    {
        ptr = new BinaryNode<Comparable>(data);
    }
    else if (data < ptr->data)
    {
        insert(data, ptr->left);
    }
    else if (data > ptr->data)
    {
        insert(data, ptr->right);
    }
}

/**
 * Public method to remove a data item from a subtree
 * and set the new root of the subtree.
 * Do nothing if the data item is not found.
 * @param data the data to remove.
 */
template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& data)
{
    remove(data, root);
}

/**
 * Protected method to remove a data item from a subtree
 * and set the new root of the subtree.
 * Do nothing if the data item is not found.
 * @param data the data to remove.
 * @param ptr pointer to the root node of the subtree.
 */
template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& data,
                                          BinaryNode<Comparable>* &ptr)
{
    if (ptr == nullptr) return;   // not found, so do nothing

    // First search for the target node to remove.
    if (data < ptr->data)
    {
        remove(data, ptr->left);
    }
    else if (data > ptr->data)
    {
        remove(data, ptr->right);
    }

    // Remove a target node with two children.
    else if (   (ptr->left  != nullptr)
             && (ptr->right != nullptr))
    {
        // Replace the target node's data with the successor node's data.
        ptr->data = findMin(ptr->right)->data;

        // Search for and remove the successor node.
        remove(ptr->data, ptr->right);
    }

    // Remove a target node with one or no children.
    else
    {
        BinaryNode<Comparable> *oldNode = ptr;
        ptr = (ptr->left != nullptr) ? ptr->left
                                       : ptr->right;
        delete oldNode;
    }
}

#endif // BINARY_TREE_CHECKER_H