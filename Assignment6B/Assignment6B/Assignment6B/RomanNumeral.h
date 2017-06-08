
#include <stdio.h>
#include <string>
#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

using namespace std;

class RomanNumeral
{
public:
    RomanNumeral();
    RomanNumeral(string roman);
    RomanNumeral(int value);
    
    friend RomanNumeral operator+(const RomanNumeral a, const RomanNumeral b);
    friend RomanNumeral operator-(const RomanNumeral a, const RomanNumeral b);
    friend RomanNumeral operator*(const RomanNumeral a, const RomanNumeral b);
    friend RomanNumeral operator/(const RomanNumeral a, const RomanNumeral b);
    friend bool operator==(const RomanNumeral a, const RomanNumeral b);
    friend bool operator!=(const RomanNumeral a, const RomanNumeral b);
    friend ostream& operator<<(ostream& os, RomanNumeral Roman);
    friend istream& operator>>(istream& in, RomanNumeral& Roman);

private:
    string roman;      // Roman numeral as a string
    int    decimal;    // decimal value of the Roman numeral
    
    char romanNum[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int intNum[7] = {1, 5, 10, 50, 100, 500, 1000};
    
    void toRoman();    // calculate string from decimal value
    void toDecimal();  // calculate decimal value from string
    string singleInttoRoman(int num, int digit);    //input sinlge digit and return roman numeral
    int singleRomantoInt(char ch);    //input single roman numeral and return digits
};

#endif /* ROMANNUMERAL_H_ */

