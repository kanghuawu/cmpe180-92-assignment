#include <string>
#include <iostream>

using namespace std;

string digits(string str);

int main(){
    string a = "Union 76";
//    cout << a[5] - '1' << endl;
    cout << digits(a) << endl;
    return 0;
}
/**
 Given a string, return a string of all digits contained in it.
 Use recursion. Do not use loops.
 A digit is a character between '0' and '9' inclusive.
 Hint: str.substr(1) is the substring of str from position 1 to
 the end.
 */
string digits(string str)
{
    if(str.length() == 0) return "";
    else if(str[0]  - '0' < 10 && str[0]  - '0' >= 0) return str[0] + digits(str.substr(1));
    else return "" + digits(str.substr(1));
}
