//
//  prog.cpp
//  HW3-3
//
//  Created by Wu Kang-Hua on 9/10/16.
//  Copyright © 2016 kanghuawu. All rights reserved.
//

#include "prog.hpp"

#include <vector>
using namespace std;

/**
 Swaps the second and second-to-last value of a.
 For example, if a is {3, 1, 4, 1, 5, 9, 2, 6}
 after calling this method it is {3, 2, 4, 1, 5, 9, 1, 6}.
 If the array has length < 2, do nothing.
 @param a a vector of integers
 */
void swap2(vector<int>& a)
{
    if (a.size()>=2) {
        int secElement = a[1];
        a[1] = a[a.size()-2];
        a[a.size()-2] = secElement;
    }
}

