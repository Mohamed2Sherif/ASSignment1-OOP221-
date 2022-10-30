#include "BigReal.h"
using namespace std;

//default constructors
BigReal::BigReal(const string &realNumber) {
    set_RealNumber(realNumber);
}

BigReal::BigReal(const double &realNumber) {
  ostringstream s;
  s<<realNumber;
  set_RealNumber(s.str());
}

BigReal::BigReal(BigDecimalInt &bigInt) {
     realNumber = bigInt.getNumber();
     Sign = bigInt.sign();
}

//copy constructor
BigReal::BigReal(const BigReal &another_realNumber) {
    copy(another_realNumber);
}

//move constructor
BigReal::BigReal(BigReal&& another_realNumber){
    realNumber = another_realNumber.realNumber;
    Sign = another_realNumber.Sign;
}

//assignment operator overloading
BigReal& BigReal::operator=(const BigReal &another_realNumber) {

    if(realNumber != another_realNumber.realNumber) {
        copy(another_realNumber);
    }

    return *this;
}

//move constructor
BigReal& BigReal::operator=(BigReal &&another_realNumber) {

    if(realNumber != another_realNumber.realNumber){

        realNumber = another_realNumber.realNumber;
        Sign = another_realNumber.Sign;

    }

    return *this;
}

//method implement deep copy
void BigReal::copy(const BigReal &another_realNumber) {
    string*copy = new string ;
    *copy = (another_realNumber.realNumber);
    realNumber = *copy;
    delete copy;
}

//setter
void BigReal::set_RealNumber(const string &realNumber) {
    this->realNumber = realNumber;
}

