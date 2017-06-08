#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string INPUT_FILE_NAME = "/Users/bondk/Dropbox/cmpe180-92-assignment/1B/Assignment1B/GettysburgAddress.txt";

int main()
{
    string line;
    int line_count = 0;
    int character_count = 0;
    int word_count = 0;
    int lower_count = 0;
    int upper_count = 0;
    int space_count = 0;
    int punctuation_count = 0;
    
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }
    
    while (getline(input,line)){
        line_count += 1;
        character_count += line.size();
        
        for (int i = 0; i < line.size(); i++) {
            if (isalnum(line[i]) && isspace(line[i+1])) {
                word_count += 1;
            }else if (isalnum(line[i]) && ispunct(line[i+1])){
                word_count += 1;
            }else if (isalnum(line[i]) && iscntrl(line[i+1])){
                word_count += 1;
            }
            
            if (islower(line[i])) {
                lower_count += 1;
            }
            if (isupper(line[i])) {
                upper_count += 1;
            }
            if (isspace(line[i])) {
                space_count += 1;
            }
            if (ispunct(line[i])) {
                punctuation_count += 1;
            }
        }
    }
    
    cout << "Statistics for file " << "GettysburgAddress.txt" << ":" << endl;
    cout << endl;
    
    
    /***** Complete this program. *****/
    
    cout << "Lines: " << line_count << endl;
    cout << "Characters: " << character_count << endl;
    cout << "Words: " << word_count << endl;
    cout << "Lower-case letters: " << lower_count << endl;
    cout << "Upper-case letters: " << upper_count << endl;
    cout << "Spaces: " << space_count << endl;
    cout << "Punctuation marks: " << punctuation_count << endl;
}
