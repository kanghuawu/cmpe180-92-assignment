/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#ifndef SHELLSORTOPTIMAL_H_
#define SHELLSORTOPTIMAL_H_

#include "VectorSorter.h"

/**
 * The class that implements the optimal shellsort algorithm
 * for a vector of data, where the diminishing increment is
 * calculated according to Don Knuth.
 */
class ShellSortOptimal: public VectorSorter
{
public:
    ShellSortOptimal();
    virtual ~ShellSortOptimal();

    virtual string name() const;
    virtual void run_sort_algorithm() throw (string);
};

#endif /* SHELLSORTOPTIMAL_H_ */