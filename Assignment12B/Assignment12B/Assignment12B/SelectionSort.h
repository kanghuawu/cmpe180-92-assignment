/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_

#include "VectorSorter.h"

/**
 * The class that implements the selection sort algorithm
 * for a vector of data.
 */
class SelectionSort: public VectorSorter
{
public:
    SelectionSort();
    virtual ~SelectionSort();

    virtual string name() const;
    virtual void run_sort_algorithm() throw (string);
};

#endif /* SELECTIONSORT_H_ */