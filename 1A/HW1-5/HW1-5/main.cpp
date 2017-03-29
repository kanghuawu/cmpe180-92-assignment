#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    cout << "Enter n: ";
    int n;
    cin >> n;
    cout << endl;
    
    // Draw the following "x in a box" pattern. There are n asterisks
    // on each side. In this example, n is 8.
    // ********
    // **    **
    // * *  * *
    // *  **  *
    // *  **  *
    // * *  * *
    // **    **
    // ********
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == n){
                cout << "*" << endl;
            }else if (i == j || i == (n+1-j)){
                cout << "*";
            }else if (i == 1 || j == 1 || i == n) {
                cout << "*" ;
            }else{
                cout << " ";
            }
        }
    }
    
    return 0;
}

