/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "InsertionSort.h"

/**
 * Default constructor.
 */
InsertionSort::InsertionSort() : VectorSorter() {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
string InsertionSort::name() const { return "Insertion sort"; }

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */
void InsertionSort::run_sort_algorithm() throw (string)
{
	//reference: https://www.youtube.com/watch?v=DFG-XuyPYUQ&t=324s
    for(int i = 0; i < size - 1; i++)
    {
    	int j = i + 1;
    	bool change = false;
    	while(j > 0 && data[j] < data[j - 1])
    	{
    		swap(j, j - 1);
    		compare_count++;
			move_count--;
			j--;
			change = true;
    	}
    	if(change) move_count++;
    	else compare_count++;
    }
}
