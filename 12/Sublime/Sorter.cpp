/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "Sorter.h"
using namespace std;

/**
 * Default constructor.
 */
Sorter::Sorter()
    : size(0), move_count(0), compare_count(0), elapsed_time(0) {}

/**
 * Destructor.
 */
Sorter::~Sorter() {}

/**
 * Get the data size.
 * @return the size.
 */
int Sorter::get_size() const  { return size; }

/**
 * Set the data size.
 * @param sz the size to set.
 */
void Sorter::set_size(int sz) { size = sz; }

/**
 * Get the number of moves during a sort.
 * @return the number of moves.
 */
long Sorter::get_move_count() const      { return move_count; }

/**
 * Get the number of compares during a sort.
 * @return the number of compares.
 */
long Sorter::get_compare_count() const      { return compare_count; }

/**
 * Sort the data by invoking the sorting algorithm.
 * Count the number of data element moves and compares.
 * Calculate the elapsed time in milliseconds.
 * @throws an exception if an error occurred.
 */
bool Sorter::sort() throw (string)
{
    move_count = 0;
    compare_count = 0;
    start_timer();

    // Sort the data according to the algorithm
    // that is defined by the sorting subclasses.
    run_sort_algorithm();

    stop_timer();
    return is_data_sorted();
}

/**
 * Start the timer before beginning a sort.
 */
void Sorter::start_timer() { timer = steady_clock::now(); }

/**
 * Stop the timer after the sort finishes.
 */
void Sorter::stop_timer()
{
    steady_clock::time_point now = steady_clock::now();
    elapsed_time = duration_cast<milliseconds>(now - timer).count();
}

/**
 * Calculate the elapsed sort time.
 * @return the elapsed time in milliseconds.
 */
long Sorter::get_elapsed_ms() const { return elapsed_time; }