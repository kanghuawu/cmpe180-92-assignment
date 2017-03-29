#include <string>
using namespace std;

class Trace
{
public:
    Trace(string s);
    Trace(const Trace& other);
    Trace& operator=(const Trace& other);
    friend ostream& operator<<(ostream& os, Trace trace);
    ~Trace();
private:
    string str;
};

