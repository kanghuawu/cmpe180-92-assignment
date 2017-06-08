/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include <iostream>
#include <ctime>

#include "VectorSorter.h"

/**
 * Default constructor.
 */
VectorSorter::VectorSorter() : Sorter() {}

/**
 * Destructor.
 */
VectorSorter::~VectorSorter() {}

/**
 * Generate the data to sort. The data can be random,
 * already sorted, sorted in reverse, or all zeros.
 * @param generator the data generator.
 * @param size the number of data elements.
 */
void VectorSorter::generate_data(DataGenerator *generator, int size)
{
    clear_data();
    generator->generate_data(data, size);
    set_size(size);
}

/**
 * Print the data elements.
 */
void VectorSorter::print_data() const
{
    int size = get_size();
    for (int i = 0; i < size; i++) cout << " " << data[i];

    cout << endl;
}

/**
 * Verify that the data is correctly sorted.
 * @return true if correctly sorted, else false.
 */
bool VectorSorter::is_data_sorted() const
{
    int sizem1 = get_size() - 1;
    for (int i = 0; i < sizem1; i++)
    {
        if (data[i] > data[i+1]) return false;  // incorrect
    }

    return true;  // correct
}

/**
 * Clear the data.
 */
void VectorSorter::clear_data()
{
    if (data.size() > 0) data.clear();
}

/**
 * Exchange the values of two data elements.
 * Counts as two moves.
 */
void VectorSorter::swap(const int index1, const int index2)
{
    int temp = data[index1];
    data[index1] = data[index2];
    data[index2] = temp;

    move_count += 2;
}