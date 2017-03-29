#include <iostream>
using namespace std;

/**
 Computes the average of all positive elements in the given array.
 @param a an array of integers
 @param alen the number of elements in a
 @return the average of all positive elements in a, or 0 if there are none.
 */
double avgpos(int a[], int alen);

int main(){
    int a[] = {1,2,3};
    double ans = avgpos(a,3);
    cout.precision(2);
    cout << fixed << ans << endl;
    return 0;
}


double avgpos(int a[], int alen)
{
    int sum=0;
    int j = 0;
    bool noInput = true;
    for (int i=0; i<alen; i++) {
        if(a[i]>0){
            noInput = false;
            sum+=a[i];
            j++;
        }
    }
    if(noInput){
        return 0;
    }
    return double(sum)/j;
}