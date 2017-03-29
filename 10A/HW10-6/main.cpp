#include <iostream>
#include "list.h"

using namespace std;

string toString(const List& lst);

inline NEList operator+=(string h, const List& t) { return NEList(h, t); }

EList nil;

int main()
{
    cout << toString(NEList("Mary", NEList("had", NEList("a", NEList("little", NEList("lamb", EList())))))) << endl;
    cout << "Expected: Mary,had,a,little,lamb" << endl;
    cout << toString("Its" += "fleece" += "was" += "white" += "as" += "snow" += nil) << endl;
    cout << "Expected: Its,fleece,was,white,as,snow" << endl;
    cout << toString("Fred" += "Wilma" += nil) << endl;
    cout << "Expected: Fred,Wilma" << endl;
    cout << toString("Fred" += nil);
    cout << "Expected: Fred" << endl;
    cout << toString(nil);
    cout << "Expected: Fred" << endl;
    return 0;
}

/**
 Look at the recursively defined List class in list.h.
 A List is either empty or it has a head and a tail.
 Implement the toString function that yields a comma-separated
 string of the list elements. No spaces, just commas.
 If the list is empty, return an empty string.
 If the list has length 1, return just the head.
 */
string toString(const List& lst)
{
    if (lst.isEmpty()) {
        return "";
    }else if (lst.tail().isEmpty()){
        return lst.head() + toString(lst.tail());
    }else{
        return lst.head() + "," + toString(lst.tail());
    }
}
