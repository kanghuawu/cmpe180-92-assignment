#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

map<string, int> startingLetterFrequency(vector<string> words);

int main()
{
    vector<string> text = { "Mary", "had", "a", "little", "lamb" };
    map<string, int> freq = startingLetterFrequency(text);
    cout << freq["M"] << endl;
    cout << "Expected: 1" << endl;
    cout << freq["l"] << endl;
    cout << "Expected: 2" << endl;
    cout << boolalpha << (freq.find("w") == freq.end()) << endl;
    cout << "Expected: true" << endl;
    vector<string> text2 = { "its", "fleece", "was", "white", "as", "snow" };
    freq = startingLetterFrequency(text2);
    cout << freq["f"] << endl;
    cout << "Expected: 1" << endl;
    cout << freq["w"] << endl;
    cout << "Expected: 2" << endl;
    cout << boolalpha << (freq.find("M") == freq.end()) << endl;
    cout << "Expected: true" << endl;
    return 0;
}

map<string, int> startingLetterFrequency(vector<string> words)
{
    map<string, int> m;
    for (vector<string>::iterator it = words.begin(); it != words.end(); it++) {
        pair<map<string, int>::iterator, bool> ret = m.insert(map<string, int>::value_type(it->substr(0, 1), 1));
        if (!ret.second) {
            ret.first->second++;
        }
    }
    return m;
}
