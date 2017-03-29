#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;

void removeOddPositions(list<int>& lst);

int main()
{
    list<int> nums = { 1, 1, 2, 3, 5, 8, 13, 21, 34 };
    removeOddPositions(nums);
    copy(nums.begin(), nums.end(),
         ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "Expected: 1 2 5 13 34" << endl;
    list<int> nums2 = { 1, 2, 3, 5, 8, 13, 21, 34 };
    removeOddPositions(nums2);
    copy(nums2.begin(), nums2.end(),
         ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "Expected: 1 3 8 21" << endl;
    return 0;
}

void removeOddPositions(list<int>& lst)
{
    list<int>::iterator it = lst.begin();
    while(it != lst.end()){
        it++;
        if (it != lst.end()) {
            it = lst.erase(it);
        }
    }
}
