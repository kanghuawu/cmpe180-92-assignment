//
//  prob.cpp
//  HW3-4
//
//  Created by Wu Kang-Hua on 9/10/16.
//  Copyright © 2016 kanghuawu. All rights reserved.
//

#include "prob.hpp"
#include <iostream>
#include <vector>
using namespace std;

/**
 Rotates a vector one position to the left.
 Returns the rotated vector without modifying the
 original.
 @param a a vector of integers
 @return the rotated vector. For example, if a is {3, 1, 4, 1, 5, 9}
 then a vector {1, 4, 1, 5, 9, 3} is returned.
 */
vector<int> rot(const vector<int>& a)
{
    vector<int> b;
    if (a.size()>1) {
        for(int i=1; i<=a.size()-1; i++){
            b.push_back(a[i]);
        }
        b.push_back(a[0]);
    }else{
        return a;
    }
    
    return b;
}