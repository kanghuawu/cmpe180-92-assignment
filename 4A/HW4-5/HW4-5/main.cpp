#include <iostream>
#include <cstring>
using namespace std;

char* longest(char** words, int n);

int main()
{
    char words[] = "Hello\0Goodbye\0Bonjour\0Arrivederci";
    char* starts[] = { words, words + 6, words + 14, words + 22 };
    char* result = longest(starts, 4);
    cout << result << endl;
    cout << "Expected: " << starts[3] << endl;
    
    result = longest(starts, 3);
    cout << result << endl;
    cout << "Expected: " << starts[1] << endl;
    
    result = longest(starts, 1);
    cout << result << endl;
    cout << "Expected: " << starts[0] << endl;
    
    return 0;
}

/**
 Given an array of strings of length n > 0, return the longest
 string. If there are multiple strings of the same maximum length,
 return the first one.
 */
char* longest(char** words, int n)
{
    char* longword = "";
    for (int i=0; i<n; i++) {
        if(strlen(words[i])>strlen(longword)){
            longword=words[i];
        }
    }
    return longword;
}

