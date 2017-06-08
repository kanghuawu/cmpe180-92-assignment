#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class WidgetReport
{
    /***** Complete this class. *****/
    
public:
    WidgetReport(ifstream& in);  // constructor
    
    void print();
    
private:
    
    ifstream *input;  // reference to the input stream
    void setStatePlantDept(string &line);
    void setOther(string &line);
    int totstate=0;
    int totplant=0;
    int totdept=0;
    int totcount=0;
    int state;
    int plant;
    int dept;
    int empid;
    int count;
    string name;
};

const string INPUT_FILE_NAME = "/Users/BondK/Cloud/Dropbox/SJSU/CMPE180-92/HW/Assignment5B/widgets.txt";

int main()
{
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }
    // Generate and print the Widget Report.
    /***** Complete this main. *****/
    WidgetReport report(input);
    report.print();
    
    input.close();
    return 0;
}

/***** Put member function definitions after the main. *****/

WidgetReport::WidgetReport(ifstream& in)
{
    
    input = &in;
}

void WidgetReport::print()
{
    cout << "STATE PLANT DEPT EMPID COUNT NAME" << endl << endl;
    string line;
    getline(*input, line);   //exclude header
    while(getline(*input, line))
    {
        setStatePlantDept(line);
        
        setOther(line);
    }
    cout << endl;
    cout << setw(28) << totdept << " TOTAL FOR DEPT  " << dept << " *" << endl;
    cout << setw(28) << totplant << " TOTAL FOR PLANT " << plant << " **" << endl;
    cout << setw(28) << totstate << " TOTAL FOR STATE " << state << " ***" << endl << endl;
    cout << setw(28) << totcount << " GRAND TOTAL " << "       ****" << endl;
}

void WidgetReport::setStatePlantDept(string &line)
{
    int newstate=stoi(line.substr(0,2));
    line=line.substr(3);
    int newplant=stoi(line.substr(0,2));
    line=line.substr(3);
    int newdept=stoi(line.substr(0,2));
    line=line.substr(3);
    if (state!=newstate&totstate!=0) {
        cout << endl << setw(28) << totdept << " TOTAL FOR DEPT  " << dept << " *" << endl;
        totdept=0;
        cout << setw(28) << totplant << " TOTAL FOR PLANT " << plant << " **" << endl;
        totplant=0;
        cout << setw(28) << totstate << " TOTAL FOR STATE " << state << " ***" << endl << endl;
        totstate=0;
    }else if (plant!=newplant&totplant!=0) {
        cout << endl << setw(28) << totdept << " TOTAL FOR DEPT  " << dept << " *" << endl;
        totdept=0;
        cout << setw(28) << totplant << " TOTAL FOR PLANT " << plant << " **" << endl << endl;
        totplant=0;
    }else if (dept!=newdept&totdept!=0) {
        cout << endl << setw(28) << totdept << " TOTAL FOR DEPT  " << dept << " *" << endl << endl;
        totdept=0;
    }
    state = newstate;
    plant = newplant;
    dept = newdept;
}

void WidgetReport::setOther(string &line)
{
    empid=stoi(line.substr(0,3));
    line=line.substr(4);
    int spaceIndex=line.find_last_of(" ");
    name=line.substr(0,spaceIndex);
    line=line.substr(spaceIndex+1);
    count=stoi(line);
    
    cout << setw(5) << state << setw(6) << plant << setw(6) << dept << setw(5) << empid << setw(6) << count << " " << name<< endl;
    totstate+=count;
    totplant+=count;
    totdept+=count;
    totcount+=count;
}


