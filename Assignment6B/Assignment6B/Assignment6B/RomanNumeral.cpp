//#include <string>
#include "RomanNumeral.h"
#include <iostream>
using namespace std;

/**
 * Default constructor.
 */
RomanNumeral::RomanNumeral() : roman(""), decimal(0){
    
}

RomanNumeral::RomanNumeral(string str){
    roman = str;
    toDecimal();
}

RomanNumeral::RomanNumeral(int num){
    decimal = num;
    toRoman();
}

void RomanNumeral::toRoman(){
    int num = decimal;
    int digit = 0;
    while(num != 0){
        string str = singleInttoRoman(num, digit);
        roman = str + roman;
        digit += 1;
        num /= 10;
    }
}

string RomanNumeral::singleInttoRoman(int num, int digit){
    string str = "";
    int remain = num % 10;
    while (remain != 0) {
        if(remain == 5){
            str = string(1, romanNum[2 * digit + 1]) + str;
            remain -= 5;
        }else if(remain == 4){
            str = string(1, romanNum[2 * digit]) + string(1, romanNum[2 * digit + 1]);
            remain -= 4;
        }else if(remain == 9){
            str = string(1, romanNum[2 * digit]) + string(1, romanNum[2 * (digit + 1)]);
            remain -= 9;
        }else{
            str += string(1, romanNum[2 * digit]);
            remain -= 1;
        }
    }
    return str;
}

void RomanNumeral::toDecimal(){
    string str = roman;
    decimal = 0;
    for(int i = 0; i < str.length(); i++){
        if(i + 1 < str.length() & singleRomantoInt(str[i + 1]) > singleRomantoInt(str[i])){
            decimal -= singleRomantoInt(str[i]);
        }else{
            decimal += singleRomantoInt(str.at(i));
        }
    }
}

int RomanNumeral::singleRomantoInt(char ch){
    for(int i = 0; i < 7; i++){
        if(ch == romanNum[i]){
            return intNum[i];
        }
    }
    return 0;
}

RomanNumeral operator+(const RomanNumeral a, const RomanNumeral b){
    RomanNumeral result(a.decimal + b.decimal);
    return result;
}

RomanNumeral operator-(const RomanNumeral a, const RomanNumeral b){
    RomanNumeral result(a.decimal - b.decimal);
    return result;
}

RomanNumeral operator*(const RomanNumeral a, const RomanNumeral b){
    RomanNumeral result(a.decimal * b.decimal);
    return result;
}

RomanNumeral operator/(const RomanNumeral a, const RomanNumeral b){
    RomanNumeral result(a.decimal / b.decimal);
    return result;
}

bool operator==(const RomanNumeral a, const RomanNumeral b){
    return a.decimal == b.decimal;
}

bool operator!=(const RomanNumeral a, const RomanNumeral b){
    return a.decimal != b.decimal;
}

ostream& operator<<(ostream& os, RomanNumeral Roman){
    os << "[" << Roman.decimal << ":" << Roman.roman << "]";
    return os;
}

istream& operator>>(istream& in, RomanNumeral& Roman){
    in >> Roman.roman;
    Roman.toDecimal();
    return in;
}
