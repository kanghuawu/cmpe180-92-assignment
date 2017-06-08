/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "QuickSortOptimal.h"
#include <iostream>
/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
QuickSortOptimal::QuickSortOptimal() {}

/**
 * Destructor.
 */
QuickSortOptimal::~QuickSortOptimal() {}

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
string QuickSortOptimal::name() const { return "Quicksort optimal"; }

/**
 * Choose a good pivot, the median-of-three:
 * The middle value of the leftmost, rightmost, and center elements.
 * This is a compromise since the most optimal pivot would be the
 * median of the subrange, but that's too expensive to compute.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 * @return the chosen pivot value.
 */
int QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{
	int med = max(min(data[left], data[right]), min(max(data[left], data[right]),data[(left + right) / 2]));
    if(med == data[left]) return left;
	else if(med == data[right]) return right;
	else return (left + right) / 2;
}
