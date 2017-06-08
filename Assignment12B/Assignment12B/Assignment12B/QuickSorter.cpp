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
    int split;
    
	if(left <= right)
	{
        compare_count++;
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
    bool change = false;
    while(i <= j)
    {

        bool change1 = false;
        while(i <= j && data[i] <= pivot_data) {
            compare_count++;
            change1 = true;
            i++;
            
        }
        if(!change1) compare_count++;
        bool change2 = false;
        while(i <= j && data[j] > pivot_data){
            compare_count++;
            change2 = true;
            j--;
        }
        if(!change2) compare_count++;
        
        bool change3 = false;
    	if(i < j)
    	{
            
            change3 = true;
    		swap(i, j);
    		i++;
    		j--;
    	}
        change = true;
    }

    swap(right, i);
    return i;
}
