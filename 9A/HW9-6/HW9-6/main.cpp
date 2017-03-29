#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

map<string, set<string>> wordsByStartingLetter(vector<string> words);

int main()
{
    vector<string> text = { "Mary", "had", "a", "little", "lamb" };
    map<string, set<string>> startingWith = wordsByStartingLetter(text);
    set<string> as = startingWith["a"];
    copy(as.begin(), as.end(),
         ostream_iterator<string>(cout, " "));
    cout << endl;
    cout << "Expected: a" << endl;
    set<string> ls = startingWith["l"];
    copy(ls.begin(), ls.end(),
         ostream_iterator<string>(cout, " "));
    cout << endl;
    cout << "Expected: lamb little" << endl;
    cout << boolalpha << (startingWith.find("f") == startingWith.end()) << endl;
    cout << "Expected: true" << endl;
    vector<string> text2 = { "its", "fleece", "was", "white", "as", "snow" };
    startingWith = wordsByStartingLetter(text2);
    as = startingWith["a"];
    copy(as.begin(), as.end(),
         ostream_iterator<string>(cout, " "));
    cout << endl;
    cout << "Expected: as" << endl;
    set<string> ws = startingWith["w"];
    copy(ws.begin(), ws.end(),
         ostream_iterator<string>(cout, " "));
    cout << endl;
    cout << "Expected: was white" << endl;
    cout << boolalpha << (startingWith.find("M") == startingWith.end()) << endl;
    cout << "Expected: true" << endl;
    return 0;
}

/**
 Makes a map associating letters with the words
 starting with that letter.
 @param words an array of strings
 @return the map
 */
map<string, set<string>> wordsByStartingLetter(vector<string> words)
{
    map<string, set<string>> m;
    for (vector<string>::iterator it = words.begin(); it != words.end(); it++) {
        m[it->substr(0, 1)].insert(*it);
    }
    return m;
}

