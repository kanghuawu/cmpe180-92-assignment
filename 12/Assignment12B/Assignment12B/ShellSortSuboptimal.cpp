/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "ShellSortSuboptimal.h"

/**
 * Default constructor.
 */
ShellSortSuboptimal::ShellSortSuboptimal() {}

/**
 * Destructor.
 */
ShellSortSuboptimal::~ShellSortSuboptimal() {}

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
string ShellSortSuboptimal::name() const { return "Shellsort suboptimal"; }

/**
 * Run the suboptimal shellsort algorithm.
 * @throws an exception if an error occurred.
 */
void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
    //my reference: https://en.wikipedia.org/wiki/Shellsort

    for(int gap = size / 2; gap > 0; gap /= 2)
    {
    	for(int i = gap; i < size; i++)
    	{
    		bool change = false;
			int j = i;
    		for(; j >= gap && data[j - gap] > data[j]; j -= gap)
    		{
    			swap(j, j - gap);
    			move_count--;
    			compare_count++;
    			change = true;
    		}
    		if(j < gap) compare_count--;
    		if(change) move_count++;
    		compare_count++;
    	}
    }
}
