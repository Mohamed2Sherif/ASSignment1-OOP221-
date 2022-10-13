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
        if (anotherDec.dec_int.length() >= dec_int.length()) {
            length = dec_int.length();
            diff = anotherDec.dec_int.length() - length;
            check_bigger = true;
        } else {
            length = anotherDec.dec_int.length();
            diff = dec_int.length() - length;
        }
        for (int i = 0; i < length; i++) {
            static int carry = 0;
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
        if (check_bigger)
            for (int i = diff - 1; i >= 0; i--) {
                result.dec_int = anotherDec.dec_int[i] + result.dec_int;
            }
        else
            for (int i = diff - 1; i >= 0; i--) {
                result.dec_int = dec_int[i] + result.dec_int;
            }
        result.dec_int.pop_back();
    }
    else if(dec_sign == '-'){

    }
    else{

    }


    return result ;
}