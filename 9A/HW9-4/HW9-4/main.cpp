#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;

void crossOver(list<int>& a, int n, list<int>& b, int m);

int main()
{
    list<int> nums1 = { 1, 2, 3, 4 };
    list<int> nums2 = { 5, 6, 7 };
    crossOver(nums1, 2, nums2, 1);
    copy(nums1.begin(), nums1.end(),
         ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "Expected: 1 2 6 7" << endl;
    copy(nums2.begin(), nums2.end(),
         ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "Expected: 5 3 4" << endl;
    return 0;
}



void crossOver(list<int>& a, int n, list<int>& b, int m)
{
    list<int>::iterator ita = a.begin();
    advance(ita, n);
    list<int>::iterator itb = b.begin();
    advance(itb, m);
    a.insert(ita, itb, b.end());
    b.insert(itb, ita, a.end());
    a.resize(4);
    b.resize(3);
}
