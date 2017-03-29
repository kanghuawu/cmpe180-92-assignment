#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Optional.h"



class Name
{
public:
    Name(string first, string last) { name = last + ", " + first; }
    friend ostream& operator<<(ostream&, const Name&);
    
private:
    string name;
};

ostream& operator<<(ostream& out, const Name& n)
{
    return out << n.name;
}

int main()
{
    Optional<string> o1("Fred");
    Optional<string> o2;
    cout << o1.getOrElse("Wilma") << endl;
    cout << "Expected: Fred" << endl;
    cout << o2.getOrElse("Wilma") << endl;
    cout << "Expected: Wilma" << endl;
    cout << boolalpha;
    cout << o1.isPresent() << endl;
    cout << "Expected: true" << endl;
    cout << o2.isPresent() << endl;
    cout << "Expected: false" << endl;
    
    Optional<Name> o3(Name("John", "Public"));
    Optional<Name> o4;
    cout << o3.getOrElse(Name("Jane", "Private")) << endl;
    cout << "Expected: Public, John" << endl;
    cout << o4.getOrElse(Name("Jane", "Private")) << endl;
    cout << "Expected: Private, Jane" << endl;
    cout << boolalpha;
    cout << o3.isPresent() << endl;
    cout << "Expected: true" << endl;
    cout << o4.isPresent() << endl;
    cout << "Expected: false" << endl;
    
    return 0;
}


