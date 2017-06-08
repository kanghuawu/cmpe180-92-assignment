/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#ifndef VECTORSORTER_H_
#define VECTORSORTER_H_

#include <string>
#include <vector>
#include "Sorter.h"
using namespace std;

/**
 * Abstract base class of the vector sorting subclasses.
 */
class VectorSorter: public Sorter
{
public:
    VectorSorter();
    VectorSorter(string name);
    virtual ~VectorSorter();

    virtual void generate_data(DataGenerator *generator, int size);
    void clear_data();
    void print_data() const;

protected:
    vector<int> data;  // the vector to sort

    bool is_data_sorted() const;
    void swap(const int index1, const int index2);
};

#endif /* VECTORSORTER_H_ */