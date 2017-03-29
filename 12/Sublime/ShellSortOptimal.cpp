/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "ShellSortOptimal.h"

/**
 * Default constructor.
 */
ShellSortOptimal::ShellSortOptimal() {}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {}

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
string ShellSortOptimal::name() const { return "Shellsort optimal"; }

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */
void ShellSortOptimal::run_sort_algorithm() throw (string)
{
    //my reference: https://en.wikipedia.org/wiki/Shellsort
	vector<int> gap_vec;
	for(int i = 0; 3 * i + 1 < size; i++) gap_vec.push_back(3 * i + 1);
    while(!gap_vec.empty())
    {
    	int gap = gap_vec.back();
    	gap_vec.pop_back();
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
