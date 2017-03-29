#include <string>
//#include <functional>

using namespace std;

#include "employee.h"

int hashCode(const double& d)
{
    const int* p = reinterpret_cast<const int*>(&d);
    return p[0] ^ p[1];
}

/**
 Implement a hash function for hashing values of class
 Employee. Return the sum of the hashes of the name and
 salary.
 
 To hash a string s, compute
 ((((s[0] * 31) + s1) * 31 + s[2]) * 31 + ... ) * 31 + s[n - 1]
 where n is the length of the string.
 
 For example, the hash code of "Fred" is
 
 ((('F' * 31 + 'r') * 31 + 'e' ) * 31) + 'd'
 
 or 2198155.
 
 To hash a double, XOR the top and bottom 4-byte parts. Use
 the supplied function.
 
 For example, the hash code of 2.0 is (0x40000000 ^ 0x00000000)
 or decimal 1073741824
 (see https://en.wikipedia.org/wiki/Double-precision_floating-point_format)
 */
int hashCode(const Employee& e)
{
    int e_name = 0;
    for (int i = 0; i < e.name().length(); i++) {
        e_name = (e_name * 31) + e.name()[i];
    }
    return hashCode(e.salary()) + e_name;
}

