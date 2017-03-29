#include <iostream>
#include "hash.h"
using namespace std;

int main() {
    cout << hashCode(Employee("Fred Fielding", 95000)) << endl;
    cout << hashCode(Employee("", 0)) << endl;
}
