#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;

void removeOdd(list<int>& lst);

int main()
{
    list<int> nums = { 1, 1, 2, 3, 5, 8, 13, 21, 34 };
    removeOdd(nums);
    copy(nums.begin(), nums.end(),
         ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "Expected: 2 8 34" << endl;
    list<int> nums2 = { 2, 3, 5, 7, 11, 13, 17, 19 };
    removeOdd(nums2);
    copy(nums2.begin(), nums2.end(),
         ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "Expected: 2" << endl;
    return 0;
}

void removeOdd(list<int>& lst)
{
    list<int>::iterator it = lst.begin();
    while(it != lst.end()){
        if ((*it % 2) != 0) {
            it = lst.erase(it);
        }else{
            it++;
        }
    }
}

