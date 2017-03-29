/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "QuickSorter.h"

/**
 * Default constructor.
 */
QuickSorter::QuickSorter() : VectorSorter() {}

/**
 * Destructor.
 */
QuickSorter::~QuickSorter() {}

/**
 * Run the quicksort algorithm.
 * @throws an exception if an error occurred.
 */
void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}

/**
 * The quicksort algorithm recursively sorts data subranges.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 */
void QuickSorter::quicksort(const int left, const int right)
{
	//reference: textbook
	// cout << endl;
	// cout << left << " " << right << " " << choose_pivot(left, right); 
	// this->print_data();
	int split;
	if(left < right)
	{
    	split = partition(left, right, choose_pivot(left, right));
    	quicksort(left, split - 1);
    	quicksort(split + 1, right);
	}
}

/**
 * Choose the pivot according to a pivot strategy.
 * The chosen pivot will be moved temporarily to the right end.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @return the pivot value.
 */
int QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

/**
 * Partition the subrange by moving data elements < pivot to the left
 * and data elements > pivot to the right.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @param pivot the pivot value.
 */
int QuickSorter::partition(const int left, const int right, const int pivot)
{
	int i = left;
	int j = right;
	int pivot_data = data[pivot];
	swap(pivot, j);
	j--;
    while(i <= j)
    {
    	// cout << "i: " << i  << " " << data[i] << " j: " << j << " " << data[j] << endl;
    	while(data[i] < pivot_data) i++;
    	while(data[j] > pivot_data) j--;
    	if(i <= j) 
    	{
    		swap(i, j);
    		i++;
    		j--;
    	}
    }
    swap(right, i);
    return i;
}
