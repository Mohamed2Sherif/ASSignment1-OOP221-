
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
       string get_dec(){
           return dec_int ;
       }
       void set_dec(string decimal){
           dec_int = decimal ;
       }
       void set_sign(char sign){
           dec_sign = sign ;
       }
       char get_sign(){
           return dec_sign ;
       }
       BigDecimalInt operator- (BigDecimalInt anotherDec);
       bool operator< (BigDecimalInt anotherDec);
       bool operator> (BigDecimalInt anotherDec);
       bool operator==(BigDecimalInt anotherDec);
       BigDecimalInt operator= (BigDecimalInt anotherDec){
           BigDecimalInt num("0") ;
           dec_int = anotherDec.dec_int ;
           dec_sign = anotherDec.dec_sign ;
           num.dec_int= dec_int ;
           num.dec_sign = dec_sign ;
           return num ;
       }
       int size();
       int sign();
};
string subtract(string num1, string num2);
#endif //OOP_ASSIGNMENT1_BIGDECIMALINT_H
