#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> digitGroups(string str);
void digitsHelper(string str, string currentDigitGroup, vector<string>& digitGroups);

int main(){
    string str = "Mississippi";
    //    cout << a[5] - '1' << endl;
    for (string st: digitGroups(str)) {
        cout << st << endl;
    }
    return 0;
}

void digitsHelper(string str, string currentDigitGroup, vector<string>& digitGroups)
{
    if (str.length() == 0 && currentDigitGroup != "") {
        digitGroups.push_back(currentDigitGroup);
    }else if (str.length() == 0){
        
    }else if (str[0]  - '0' < 10 && str[0]  - '0' >= 0){
        currentDigitGroup += str[0];
        digitsHelper(str.substr(1), currentDigitGroup, digitGroups);
    }else{
        if (currentDigitGroup != "") {
            digitGroups.push_back(currentDigitGroup);
            currentDigitGroup = "";
        }
        digitsHelper(str.substr(1), currentDigitGroup, digitGroups);
    }
}

/**
 Given a string, return a vector of all substrings consisting of
 digits contained in it. For example, if str is "I like 7 and 13",
 return a vector containing "7" and "13".
 Use a recursive helper method. Do not use loops.
 A digit is a character between '0' and '9' inclusive.
 
 */
vector<string> digitGroups(string str)
{
    vector<string> result;
    digitsHelper(str, "", result);
    return result;
}
