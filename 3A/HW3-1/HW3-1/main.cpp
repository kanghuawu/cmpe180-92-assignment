#include <iostream>
using namespace std;


/*
 Read numbers from standard input and print the average of
 all positive numbers, with two digits after the decimal point.
 
 The end of input is indicated by a number 0. For example,
 if the input is
 
 1 2 4 -3 5 -6 0
 
 then you print "Average: 3.00". If there are no positive elements,
 print "Average: 0.00".
 */

int main()
{
    int sum = 0;
    int i = 0;
    int num;
    bool noPosi = true;
    cin >> num;
    while(num!=0){
        noPosi = false;
        sum += num;
        i++;
        cin >> num;
    }
    if(noPosi){
        cout << "Average: 0.00" << endl;
    }
    cout.precision(2);
    cout << "Average: " << fixed << double(sum)/i << endl;
    return 0;
}

