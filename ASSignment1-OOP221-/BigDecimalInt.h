#ifndef OOP_ASSIGNMENT1_BIGDECIMALINT_H
#define OOP_ASSIGNMENT1_BIGDECIMALINT_H
#include<bits/stdc++.h>
#include<regex>
using namespace std ;

class BigDecimalInt{
private:
    string dec_int="0" ;
    char dec_sign = '+' ;

public:
       BigDecimalInt (string decStr);
       BigDecimalInt (int decInt);
       BigDecimalInt operator+ (BigDecimalInt anotherDec);
       BigDecimalInt operator- (BigDecimalInt anotherDec);
       bool operator< (const BigDecimalInt& anotherDec);
       bool operator> (const BigDecimalInt& anotherDec);
       bool operator==(const BigDecimalInt& anotherDec);
       BigDecimalInt& operator=(const BigDecimalInt& anotherDec);
       friend ostream& operator << (ostream& out, BigDecimalInt b);
       string get_dec();
       void set_dec(string decimal);
       void set_sign(char sign);
       char sign() const;
       int size()const;

};

string subtract(string num1, string num2);
#endif //OOP_ASSIGNMENT1_BIGDECIMALINT_H
