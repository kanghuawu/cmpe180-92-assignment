/**
 * Test the binary search tree and AVL tree implementations.
 * The AVL tree is derived from the binary search tree.
 *
 * Create a tree of height 5 and then repeatedly
 * delete the root. The AVL tree should remain balanced
 * after each node insertion and deletion.
 *
 * Author: Ron Mak
 *         Department of Computer Engineering
 *         San Jose State University
 */
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

#include "BinarySearchTree.h"
#include "AvlTree.h"
#include "BinaryTreeChecker.h"
#include "BinaryTreePrinter.h"

using namespace std;
using namespace std::chrono;

void rand_generator(int N, vector<int>& rand_vec);
void makeTree(BinarySearchTree<int>& tree, vector<int> rand_vec);
void searchTree(BinarySearchTree<int>& tree, vector<int> rand_vec);
const int N[] = {1000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
/**
 * Main.
 */
int main( )
{
    BinarySearchTree<int>  BSTtree;
    AvlTree<int>  Avltree;
    vector<int> to_make;
    vector<int> to_search;
    
    cout << setw(10) << " " << setw(20) << "Insertion (ms)" << setw(20) << "Search (ms)" << setw(16) << "Height" <<endl;
    cout << setw(10) << "# of Nodes" << setw(10) << "BST" << setw(10) << "AVL" << setw(10) << "BST" << setw(10) << "AVL" << setw(8) << "BST" << setw(8) << "AVL" << endl;
    for(int n : N){
        cout << setw(10) <<  n;
        rand_generator(n, to_make);
        steady_clock::time_point start_time = steady_clock::now();
        makeTree(BSTtree, to_make);
        steady_clock::time_point end_time = steady_clock::now();
        long elapsed_time = duration_cast<milliseconds>(end_time - start_time).count();
        cout << setw(10) << elapsed_time;
        
        start_time = steady_clock::now();
        makeTree(Avltree, to_make);
        end_time = steady_clock::now();
        elapsed_time = duration_cast<milliseconds>(end_time - start_time).count();
        cout << setw(10) << elapsed_time;
        
        rand_generator(n, to_search);
        start_time = steady_clock::now();
        searchTree(BSTtree, to_search);
        end_time = steady_clock::now();
        elapsed_time = duration_cast<milliseconds>(end_time - start_time).count();
        cout << setw(10) << elapsed_time;
        
        start_time = steady_clock::now();
        searchTree(Avltree, to_search);
        end_time = steady_clock::now();
        elapsed_time = duration_cast<milliseconds>(end_time - start_time).count();
        cout << setw(10) << elapsed_time;
        
        cout << setw(8) << BSTtree.height();
        cout << setw(8) << Avltree.BinarySearchTree::height() << endl;
        
        BSTtree.clear();
        Avltree.clear();
        to_make.clear();
        to_search.clear();
    }
}


void rand_generator(int n, vector<int>& rand_vec){
    int r;
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        r = rand() % n;
        rand_vec.push_back(r);
    }
}


void makeTree(BinarySearchTree<int>& tree, vector<int> rand_vec)
{
    for (int i = 0; i < rand_vec.size(); i++) tree.insert(rand_vec[i]);
}


void searchTree(BinarySearchTree<int>& tree, vector<int> rand_vec)
{
    for (int i = 0; i < rand_vec.size(); i++) tree.contains(rand_vec[i]);
}
