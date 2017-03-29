#include <string>
#include <iostream>

using namespace std;

string mesh(string a, string b);

int main(){
    string a = "aaa";
    string b = "b";
    string c = "";
//    cout << c.substr(0, 1) << endl;
    cout << mesh(a, b) << endl;
    return 0;
}
/**
 Mesh two strings by alternating characters from them. If one string
 runs out before the other, just pick from the longer one.
 For example, mesh("Fred", "Wilma") is "FWrieldma".
 Use recursion. Do not use loops.
 Hint: str.substr(1) is the substring of str from position 1 to
 the end.
 */
string mesh(string a, string b)
{
    if (a.length() == 0 && b.length() == 0) {
        return "";
    }else{
        string aa;
        string bb;
        if (a.length() == 0) aa = "";
        else aa = a.substr(1);
        if (b.length() == 0) bb = "";
        else bb = b.substr(1);
        return a.substr(0, 1) + b.substr(0, 1) + mesh(aa, bb);
    }
}

