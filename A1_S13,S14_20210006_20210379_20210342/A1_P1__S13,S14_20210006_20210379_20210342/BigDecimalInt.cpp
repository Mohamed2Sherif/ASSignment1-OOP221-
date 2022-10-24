#include"BigDecimalInt.h"

BigDecimalInt::BigDecimalInt(string decStr) {

    regex valid("[+-]?[0-9]+") ;
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
        dec_int = to_string(decInt) ;
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
            // convert and add the two numbers together
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
                    if(num>9) {
                        carry = 1;
                        num -= 10 ;
                    }
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
                if (carry) {
                    int num = (dec_int[i] - '0') + carry;
                    if (num > 9) {
                        carry = 1;
                        num -= 10 ;
                    }
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
        result.dec_int.pop_back() ;
    }
    else if(dec_sign == '-'){
        result.dec_int =subtract(get_dec(),anotherDec.get_dec()) ;
        reverse(result.dec_int.begin(), result.dec_int.end());
        if(dec_int.length()<anotherDec.dec_int.length())
            result.dec_sign = '+' ;
        else if(dec_int.length()>anotherDec.dec_int.length())
            result.dec_sign = '-' ;
        else{
            if(anotherDec.dec_int>dec_int) {
                result.dec_sign = '+' ;
            }
            else if(anotherDec.dec_int<dec_int){
                result.dec_sign = '-' ;
            }
            else{
                result.dec_sign = ' ' ;
            }
        }
    }
    else{
        result.dec_int =  subtract(anotherDec.get_dec(),get_dec()) ;
        reverse(result.dec_int.begin(), result.dec_int.end());
        if(dec_int.length()>anotherDec.dec_int.length())
            result.dec_sign = '+' ;
        else if(dec_int.length()<anotherDec.dec_int.length())
            result.dec_sign = '-' ;
        else{
            if(anotherDec.dec_int<dec_int) {
                result.dec_sign = '+' ;
            }
            else if(anotherDec.dec_int > dec_int){
                result.dec_sign = '-' ;
            }
            else{
                result.dec_sign = ' ' ;
            }
        }
    }
    while(result.dec_int[0]=='0' && result.dec_int.length()>1){
        result.dec_int.erase(result.dec_int.begin()) ;
    }
    return result ;
}


//num2 - num1
string subtract(string num1, string num2){
    static int carry = 0 ;
    int temp ;
    string res = "0" ;
    int length, diff=0 ;
    bool check_bigger ;

    if(num1.length()==num2.length())
    {
        if(num2.compare(num1)>0) {
            for(int i=0;i<num1.length();i++){
                temp = (num2[num2.length()-i-1]-'0') - (num1[num1.length()-i-1]-'0') - carry ;
                if(temp<0){
                    temp+= 10 ;
                    carry = 1 ;
                }
                else{
                    carry = 0 ;
                }
                res += to_string(temp) ;
            }
        }
        else if(num2.compare(num1)==0){
            res += "0" ;
        }
        else {
            swap(num1,num2) ;
            for(int i=0;i<num1.length();i++){

                temp = (num2[num2.length()-i-1]-'0') - (num1[num1.length()-i-1]-'0')- carry ;
                if(temp<0){
                    temp += 10 ;
                    carry = 1 ;
                }
                else{
                    carry = 0 ;
                }
                res += to_string(temp) ;
            }
        }
    }
    else {

        if (num1.length() > num2.length()) {
            length = num2.length();
            diff = num1.length() - length;
            check_bigger = true;
            for (int i = 0; i < num2.length(); i++) {

                temp = (num1[num1.length() - i - 1] - '0') - (num2[num2.length() - i - 1] - '0') - carry;
                if (temp < 0) {
                    temp += 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                res += to_string(temp);
            }

        }
        else {
            length = num1.length();
            diff = num2.length() - length;
            check_bigger = false;

            for (int i = 0; i < num1.length(); i++) {

                temp = (num2[num2.length() - i - 1] - '0') - (num1[num1.length() - i - 1] - '0') - carry;
                if (temp < 0) {
                    temp += 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                res += to_string(temp);
            }
        }
        if (check_bigger) {
            for (int i = diff - 1; i >= 0; i--) {
                if(carry){
                    int num = (num1[i]-'0') - carry ;
                    if(num<0) {
                        carry = 1;
                        num+= 10 ;
                    }
                    else
                        carry = 0 ;
                    res += to_string(num) ;
                }
                else
                    res += num1[i] ;
            }
        }
        else
            for (int i = diff - 1; i >= 0; i--) {
                if(carry) {
                    int num = (num2[i] - '0') - carry;
                    if (num < 0) {
                        carry = 1;
                        num += 10 ;
                    }
                    else
                        carry = 0 ;
                    res += to_string(num) ;
                }
                else
                    res += num2[i] ;
            }
        if(carry) {
            res += to_string(carry) ;
        }

    }
    res = res.substr(1) ;
    return res ;
}


//number setter
void BigDecimalInt::set_dec(string decimal){
    dec_int = decimal ;
}

//sign setter
void BigDecimalInt::set_sign(char sign){
    dec_sign = sign ;
}

// number getter
string BigDecimalInt::get_dec(){
    return dec_int ;
}

//size getter
int BigDecimalInt::size()const{
    return this->dec_int.size();
}

//sign getter
char BigDecimalInt::sign() const{
    return dec_sign ;
}

//overload = operator
BigDecimalInt& BigDecimalInt::operator = (const BigDecimalInt& anotherDec){
    BigDecimalInt num("0") ;
    dec_int = anotherDec.dec_int ;
    dec_sign = anotherDec.dec_sign ;
    num.dec_int= dec_int ;
    num.dec_sign = dec_sign ;
    return *this;
}

//overload << operator
ostream& operator << (ostream& out, BigDecimalInt b){
    out<<b.dec_sign<<b.dec_int;
}

//overload == operator
bool BigDecimalInt::operator == (const BigDecimalInt& anotherDec){
    return this->dec_int == anotherDec.dec_int;
}

//overload >operator
bool BigDecimalInt::operator > (const BigDecimalInt& anotherDec) {
    return this->dec_int > anotherDec.dec_int;
}

bool BigDecimalInt::operator < (const BigDecimalInt& anotherDec){
    return this->dec_int < anotherDec.dec_int;
}
BigDecimalInt BigDecimalInt::operator- (BigDecimalInt anotherDec)
{
    static int carry = 0 ;
    string operation ;
    BigDecimalInt result("0");
    int length, diff=0 ;
    bool check_bigger ;
    if(dec_sign == '+' && anotherDec.dec_sign == '+')
    {
        result.dec_sign =result.dec_sign;
    }
    else if(dec_sign == '-' && anotherDec.dec_sign == '+')
    {

        //ADD with negative sign
        operation ="ADDWNSIGN";
        //opearation is adition but result in negative sign
    }
    else if(dec_sign == '+' && anotherDec.dec_sign == '-')
    {

        operation ="ADD";
    }
    else if(dec_sign == '-' && anotherDec.dec_sign == '-' )
    {
        if(dec_int.compare(anotherDec.dec_int)>0)
        {
            result.dec_sign ='-';
        }
        else
        {
            result.dec_sign = '+';
        }


        result =this->operator+(anotherDec.dec_int);
//        result.dec_int.pop_back();
        return result;

    }
    else {
        result.dec_sign = '+';

    }
    if (operation == "ADDWNSIGN")
    {
        this->dec_sign ='+';
        anotherDec.dec_sign= '+';
        result = this->operator+(anotherDec);
        result.dec_sign = '-';
        return result;
    }
    else if(operation == "ADD")
    {
        anotherDec.dec_sign ='+';
        return this->operator+(anotherDec);
    }
    if (anotherDec.dec_int.length() > dec_int.length()) {

        length = dec_int.length();
        diff = anotherDec.dec_int.length() - length;
        check_bigger = false;
    }
    else if(anotherDec.dec_int.length() == dec_int.length())
    {
        if (anotherDec.dec_int.compare(dec_int) >0)
        {
            length = dec_int.length();
            diff = anotherDec.dec_int.length() - length;
            check_bigger = false;
        }
        else
        {
            length = anotherDec.dec_int.length();
            diff = dec_int.length() - length;
            check_bigger = true ;
        }
    }

    else {
        length = anotherDec.dec_int.length();
        diff = dec_int.length() - length;
        check_bigger = true ;
    }
    if(check_bigger)
    {

        result.dec_sign ='+';
        for(int i =0; i <length; i++)
        {
            if(carry == -1 && dec_int[dec_int.length() - i - 1] != '0')
            {
                dec_int[dec_int.length() - i - 1] -=1;
                carry =0;
            }
            else if(carry == -1 && dec_int[dec_int.length() - i - 1] =='0')
            {
                dec_int[dec_int.length() - i - 1] +=9;
                carry= -1;
            }

            if((dec_int[dec_int.length() - i - 1] ) <( anotherDec.dec_int[anotherDec.dec_int.length() - i - 1]))
            {
                //make sure the carry number is not


                int temp = (dec_int[dec_int.length() - i - 1] - '0') + 10 - (anotherDec.dec_int[anotherDec.dec_int.length() - i - 1] - '0');
                string temps = to_string(temp);
                result.dec_int = temps + result.dec_int;
                carry = -1;
            }
            else
            {
                int temp = (dec_int[dec_int.length() - i - 1] - '0')  - (anotherDec.dec_int[anotherDec.dec_int.length() - i - 1] - '0');
                string temps =to_string(temp);
                result.dec_int = temps + result.dec_int;
            }
        }



        for(int  i=0 ; i <diff; i++)
        {
            if (carry == -1 && dec_int[diff-i-1] !='0')
            {
                carry =0;
                dec_int[diff-i-1] -=1;
            }
            else if (carry == -1 && dec_int[diff-i-1] =='0')
            {
                carry=-1;
                dec_int[diff-i-1] +=9;
            }
            char temps = (dec_int[diff-i-1]);
            result.dec_int = temps + result.dec_int;
        }



    }
//   // if the second number is bigger
    else
    {


        result.dec_sign ='-';
        for(int i=0; i <length; i++)
        {
            if(carry == -1 && anotherDec.dec_int[anotherDec.dec_int.length() - i - 1] !='0')
            {
                anotherDec.dec_int[anotherDec.dec_int.length() - i - 1] -=1;
                carry =0;
            }
            else if(carry == -1 && anotherDec.dec_int[anotherDec.dec_int.length() - i - 1] =='0')
            {
                anotherDec.dec_int[anotherDec.dec_int.length() - i - 1] +=9;
                carry= -1;
            }
            if(( anotherDec.dec_int[anotherDec.dec_int.length() - i - 1]) < (dec_int[dec_int.length() - i - 1] ) )
            {
                // temp number is the number i took carry from

                int temp = (( anotherDec.dec_int[anotherDec.dec_int.length() - i - 1]-'0')+10 -(dec_int[dec_int.length() - i - 1] - '0') );
                string temps =to_string(temp);
                result.dec_int = temps + result.dec_int;
                carry= -1;
            }
            else
            {
                int temp = (( anotherDec.dec_int[anotherDec.dec_int.length() - i - 1]-'0') -(dec_int[dec_int.length() - i - 1] - '0') );
                string temps =   to_string(temp);
                result.dec_int = temps + result.dec_int;

            }
        }
        for(int  i=0 ; i <diff; i++)
        {
            if (carry == -1 && anotherDec.dec_int[diff-i-1] != '0')
            {
                carry =0;
                anotherDec.dec_int[diff-i-1] -=1;
            }
            else if (carry == -1 && anotherDec.dec_int[diff-i-1] == '0')
            {
                carry=-1;
                anotherDec.dec_int[diff-i-1] +=9;
            }
            char temps = (anotherDec.dec_int[diff-i-1]);
            result.dec_int = temps + result.dec_int;

        }

    }









    result.dec_int.pop_back();

    return result ;
}

