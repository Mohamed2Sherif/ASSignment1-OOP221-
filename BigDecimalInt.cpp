#include"BigDecimalInt.h"
BigDecimalInt::BigDecimalInt(string decStr) {

    regex valid("[+-]*[0-9]+") ;
    if(regex_match(decStr,valid)) {
        if(isdigit(decStr[0]))
        dec_int = decStr;
        else{
            dec_int = decStr.substr(1) ;
            dec_sign = decStr[0] ;
        }
        while(dec_int[0]=='0' && dec_int.length()>1){
            dec_int.erase(dec_int.begin()) ;
        }
    }
    else{
        cout<<"invalid input\n" ;
    }
}
BigDecimalInt::BigDecimalInt (int decInt ){
    string temp = to_string(decInt) ;
    if(isdigit(temp[0]))
    dec_int =to_string(decInt) ;
    else{
        dec_int = temp.substr(1) ;
        dec_sign = temp[0] ;
    }
}
BigDecimalInt BigDecimalInt:: operator+ (BigDecimalInt anotherDec){
    int length, diff=0 ;
    bool check_bigger ;
    BigDecimalInt result("0") ;
    if(dec_sign == anotherDec.dec_sign) {
        result.dec_sign = dec_sign ;
        if (anotherDec.dec_int.length() >= dec_int.length()) {
            length = dec_int.length();
            diff = anotherDec.dec_int.length() - length;
            check_bigger = true;
        } else {
            length = anotherDec.dec_int.length();
            diff = dec_int.length() - length;
            check_bigger = false ;
        }
        static int carry = 0 ;
        for (int i = 0; i < length; i++) {

            int temp = (dec_int[dec_int.length() - i - 1] - '0') +
                       (anotherDec.dec_int[anotherDec.dec_int.length() - i - 1] - '0') + carry;
            if (temp > 9) {
                carry = 1;
                result.dec_int += to_string(temp - 10);
            } else {
                carry = 0;
                result.dec_int += to_string(temp);
            }
        }

        reverse(result.dec_int.begin(), result.dec_int.end());
        if (check_bigger) {
            for (int i = diff - 1; i >= 0; i--) {
                if(carry){
                    int num = (anotherDec.dec_int[i]-'0') + carry ;
                    if(num>9)
                        carry = 1 ;
                    else
                        carry = 0 ;
                    result.dec_int = to_string(num) + result.dec_int;
                }
                else
                result.dec_int = anotherDec.dec_int[i] + result.dec_int;
            }
        }
        else
            for (int i = diff - 1; i >= 0; i--) {
                if(carry){
                    int num = (dec_int[i]-'0') + carry ;
                    if(num>9)
                        carry = 1 ;
                    else
                        carry = 0 ;
                    result.dec_int = to_string(num) + result.dec_int;
                }
                else
                result.dec_int = dec_int[i] + result.dec_int;
            }
        if(carry) {
            result.dec_int = to_string(carry) + result.dec_int;
        }
    }
    else if(dec_sign == '-'){
        result.dec_int =subtract(get_dec(),anotherDec.get_dec()) ;
        if(dec_int.length()<anotherDec.dec_int.length())
            result.dec_sign = '+' ;
        else if(dec_int.length()>anotherDec.dec_int.length())
            result.dec_sign = '-' ;
        else{
            if(anotherDec.dec_int>dec_int) {
              result.dec_sign = '+' ;
            }
            else{
              result.dec_sign = '-' ;
            }
        }
    }
    else{
        result.dec_int =  subtract(anotherDec.get_dec(),get_dec()) ;
        if(dec_int.length()>anotherDec.dec_int.length())
            result.dec_sign = '+' ;
        else if(dec_int.length()<anotherDec.dec_int.length())
            result.dec_sign = '-' ;
        else{
            if(anotherDec.dec_int[0]<dec_int[0]) {
                result.dec_sign = '+' ;
            }
            else{
                result.dec_sign = '-' ;
            }
        }
    }

    result.dec_int.pop_back();
    return result ;
}
//num2 - num1
string subtract(string num1, string num2){
        static int carry = 0 ;
        int temp ;
        string res = "0" ;

        if(num1.length()==num2.length())
        {
            if(num2>num1) {
                for(int i=0;i<num1.length();i++){
                    if(num2[num2.length()-i-1]>=num1[num1.length()-i-1]){
                        temp = (num2[num2.length()-i-1]-'0') - (num1[num1.length()-i-1]-'0')- carry ;
                        res += to_string(temp) ;
                        carry = 0 ;
                    }
                    else{
                        temp = (num2[num2.length()-i-1]-'0')+10 -(num1[num1.length()-i-1])- carry ;
                        carry = 1 ;
                        res += to_string(temp) ;
                    }
                }
            }
            else {
                swap(num1,num2) ;
                for(int i=0;i<num1.length();i++){
                    if(num2[num2.length()-i-1]>num1[num1.length()-i-1]){
                        temp = (num2[num2.length()-i-1]-'0') - (num1[num1.length()-i-1]-'0')- carry ;
                        res += to_string(temp) ;
                        carry = 0 ;
                    }
                    else{
                        temp = (num2[num2.length()-i-1]-'0')+10 -(num1[num1.length()-i-1])- carry ;
                        carry = 1 ;
                        res += to_string(temp) ;
                    }
                }
            }
        }
        else {
            if(num1.length()> num1.length()){
                swap(num1,num2) ;
            }
            for (int i = 0; i < num1.length(); i++) {
                if (num2[num2.length() - i - 1] >= num1[num1.length() - i - 1]) {
                    temp = (num2[num2.length() - i - 1] - '0') - (num1[num1.length() - i - 1] - '0') - carry;
                    res += to_string(temp);
                    carry = 0;
                } else {
                    temp = (num2[num2.length() - i - 1] - '0') + 10 - (num1[num1.length() - i - 1]) - carry;
                    carry = 1;
                    res += to_string(temp);
                }
            }
        }



    return res ;
}