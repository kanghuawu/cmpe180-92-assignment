/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#ifndef QUICKSORTMALIK_H_
#define QUICKSORTMALIK_H_

#include "QuickSorter.h"

/**
 * The class that implements the optimal quicksort algorithm
 * for a vector of data by using a good pivot strategy.
 */
class QuickSortMalik: public QuickSorter
{
public:
    QuickSortMalik();
    virtual ~QuickSortMalik();
    
    virtual string name() const;
    
private:
    virtual int choose_pivot_strategy(const int left, const int right);
};

#endif /* QUICKSORTOPTIMAL_H_ */
