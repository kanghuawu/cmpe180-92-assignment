#include <iostream>
#include <cstring>

using namespace std;

char** split(char* words);

int main()
{
    char words[] = "Hello Goodbye Bonjour Arrivederci";
    char** result = split(words);
    cout << result[0] << endl;
    cout << "Expected: " << "Hello" << endl;
    cout << result[1] << endl;
    cout << "Expected: " << "Goodbye" << endl;
    cout << result[2] << endl;
    cout << "Expected: " << "Bonjour" << endl;
    cout << result[3] << endl;
    cout << "Expected: " << "Arrivederci" << endl;
    delete [] result;
    
//    char morewords[] = "Hello  Goodbye"; // Note two spaces
//    result = split(morewords);
//    cout << result[0] << endl;
//    cout << "Expected: " << "Hello" << endl;
//    cout << strlen(result[1]) << endl;
//    cout << "Expected: " << 0 << endl;
//    cout << result[2] << endl;
//    cout << "Expected: " << "Goodbye" << endl;
//    
//    delete [] result;
    return 0;
}

/**
 Given a '\0'-terminated character array, split it by replacing
 each space in the character array with a '\0' and return a
 newly allocated array of char* pointers to the resulting strings.
 */
char** split(char* words)
{
    int count=0;
    // count spaces
    char *space=strchr(words, ' ');
    while (space != NULL) {
        *space = '\0';
        space = strchr(space+1, ' ');
        count++;
        
    }
    // store results
    char** result = new char*[count+1];
    result[0] = words;
    for (int i=1; i<count+1; i++) {
        result[i] = result[i-1] + strlen(result[i-1]) +1;
    }
    return result;
}
