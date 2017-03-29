#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    cout << "Enter values, -1 when done: ";
    int result = -1;
    // Read in numbers from cin. Stop when a value of -1 is entered.
    // Print the input that is closest to 100. If there are multiple
    // inputs that have the same minimal distance 100,
    // print the first one.
    // If no input was provided (other than the -1 sentinel),
    // print -1
    int newNum;
    while(true) {
        cin >> newNum;
        if(newNum == -1){
            break;
        }
        if (abs(100-newNum) < abs(100-result)) {
            result = newNum;
        }
    }

    cout << endl << "Result: " << result << endl;
    return 0;
}
