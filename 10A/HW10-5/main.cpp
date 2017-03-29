#include <string>
#include <vector>
#include <iostream>

using namespace std;

int altSumHelper(int n, vector<int> v);
int altSum(vector<int> v);

int main(){
    vector<int> v = {1, 2, 3, 4, 5, 6};
    cout << altSum(v) << endl;
    return 0;
}

int altSumHelper(int n, vector<int> v)
{
    if (n == v.size() || v.size() == 0) {
        return 0;
    }else if (n % 2){
        return -1 * v.at(n) + altSumHelper(n + 1, v);
    }else{
        return v.at(n) + altSumHelper(n + 1, v);
    }
}

/**
 Given a vector of integers, return the alternating sum
 v[0] - v[1] + v[2] - v[3] + ...
 If the vector is empty, the alternating sum is zero.
 Use a recursive helper method. Do not use loops.
 
 */
int altSum(vector<int> v)
{
    return altSumHelper(0, v);
}

