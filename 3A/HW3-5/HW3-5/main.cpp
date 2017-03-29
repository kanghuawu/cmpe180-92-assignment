//
//  main.cpp
//  HW3-5
//
//  Created by Wu Kang-Hua on 9/10/16.
//  Copyright © 2016 kanghuawu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> rot(const vector<int>& a, int n);
vector<vector<int>> allrot(const vector<int>& a);

int main() {
    vector<int> a = {1, 7, 2, 9};
    vector<int> b = rot(a, 3);
    vector<vector<int>> c = allrot(a);
    cout << "{";
    for(int i=0; i<c.size(); i++){
        cout << "{";
        for(int j=0; j<c.size(); j++){
            cout << c[i][j];
            if(j != c.size()-1){
                cout << ",";
            }
        }
        cout << "}";
        if(i != c.size()-1){
            cout << ",";
        }
    }
    cout << "}" << endl;
    return 0;
}

/**
 Computes all rotations of a given vector.
 @param a a vector of integers
 @return a vector of all rotations, first by 0, then by
 one, two, and so on, up to n - 1, where n is the size
 of the vector. For example, if a is {1, 7, 2, 9}
 then an array {{1, 7, 2, 9}, {7, 2, 9, 1}, {2, 9, 1, 7}, {9, 1, 7, 2}} is returned.
 */

vector<vector<int>> allrot(const vector<int>& a)
{
    if(a.empty()){
        return {};
    }
    vector<vector<int>> b;
    for (int i=0; i<=a.size()-1; i++) {
        b.push_back(rot(a,i));
    }
    return b;
}

vector<int> rot(const vector<int>& a, int n)
{
    vector<int> b(a.begin()+n, a.end());
    b.insert(b.end(), a.begin(), a.begin()+n);
    return b;
}
