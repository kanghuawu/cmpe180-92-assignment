/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#ifndef QUICKSORTSUBOPTIMAL_H_
#define QUICKSORTSUBOPTIMAL_H_

#include "QuickSorter.h"

/**
 * The class that implements the suboptimal quicksort algorithm
 * for a vector of data by using a bad pivot strategy.
 */
class QuickSortSuboptimal: public QuickSorter
{
public:
    QuickSortSuboptimal();
    virtual ~QuickSortSuboptimal();

    virtual string name() const;

private:
    virtual int choose_pivot_strategy(const int left, const int right);
};

#endif /* QUICKSORTSUBOPTIMAL_H_ */