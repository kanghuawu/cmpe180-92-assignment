/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#ifndef SHELLSORTSUBOPTIMAL_H_
#define SHELLSORTSUBOPTIMAL_H_

#include "VectorSorter.h"

/**
 * The class that implements the suboptimal shellsort algorithm
 * for a vector of data, where the diminishing increment is halved
 * for each pass.
 */
class ShellSortSuboptimal: public VectorSorter
{
public:
    ShellSortSuboptimal();
    virtual ~ShellSortSuboptimal();

    virtual string name() const;
    virtual void run_sort_algorithm() throw (string);
};

#endif /* SHELLSORTSUBOPTIMAL_H_ */