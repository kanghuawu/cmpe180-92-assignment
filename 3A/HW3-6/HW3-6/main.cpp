//
//  main.cpp
//  HW3-6
//
//  Created by Wu Kang-Hua on 9/10/16.
//  Copyright © 2016 kanghuawu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string splice(string a, string b);

int main() {
    string a = "Hello";
    string b = "Goodbye";
    cout << splice(a,b) << endl;
    return 0;
}

string splice(string a, string b)
{
    int len = max(a.size(),b.size());

    string ans;
    for(int i=0; i<len; i++){
        if(a[i] != (char)0) ans += a[i];
        if(b[i] != (char)0) ans += b[i];
    }
    return ans;
}