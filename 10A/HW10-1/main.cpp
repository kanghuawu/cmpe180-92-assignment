#include <string>
#include <iostream>

using namespace std;

bool allSame(string str);

int main(){
    string str = "aaa";
    cout << allSame(str) << endl;;
    return 0;
}

/**
 Return true if the given string contains identical
 characters or is empty. Use recursion. Do not use loops.
 Hint: str.substr(1) is the substring of str from position 1 to
 the end.
 */
bool allSame(string str)
{
    if (str.empty() || str.length() == 1) {
        return true;
    }else if(str.substr(0, 1) == str.substr(1, 1)){
        return allSame(str.substr(1));
    }else{
        return false;
    }
}

