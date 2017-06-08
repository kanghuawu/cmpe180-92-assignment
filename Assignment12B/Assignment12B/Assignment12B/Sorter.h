/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#ifndef SORTER_H_
#define SORTER_H_

#include <string>
#include <vector>
#include <ctime>
#include <chrono>
#include "DataGenerator.h"

using namespace std;
using namespace std::chrono;

/**
 * The abstract base class of the sorting subclasses.
 */
class Sorter
{
public:
    Sorter();
    virtual ~Sorter();

    // Name of the sorting algorithm.
    virtual string name() const = 0;

    // Size (number of data elements) to sort.
    int get_size() const;
    void set_size(int sz);

    // Get the number of data element moves and compares
    // during a sort, and the elapsed time in milliseconds.
    long get_move_count() const;
    long get_compare_count() const;
    long get_elapsed_ms() const;

    // Abstract functions to generate the data to sort.
    virtual void generate_data(DataGenerator* generator, int size) = 0;

    // Sort the data. Not abstract!
    virtual bool sort() throw (string);

    virtual void clear_data() = 0;
    virtual void print_data() const = 0;  // useful for debugging

protected:
    int size;            // number of data elements to sort
    long move_count;     // count of data element moves during a sort
    long compare_count;  // count of data element compares during a sort

    // Abstract functions to run a sort algorithm
    // and to verify a correct sort.
    virtual void run_sort_algorithm() throw (string) = 0;
    virtual bool is_data_sorted() const = 0;

private:
    steady_clock::time_point timer;
    long elapsed_time;

    void start_timer();
    void stop_timer();
};

#endif /* SORTER_H_ */