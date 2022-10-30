#ifndef BIGREAL_BIGREAL_H
#define BIGREAL_BIGREAL_H

#include <iostream>
#include "BigDecimalIntClass.h"

class BigReal {
private:
    string realNumber;
    BigDecimalInt bigInt;
    char Sign;

    void copy(const BigReal& another_realNumber);
public:
    BigReal():Sign('\0'){}
    BigReal(const string &realNumber);
    BigReal(const double &realNumber);
    BigReal(BigDecimalInt &bigInt);
    BigReal(const BigReal& another_realNumber);
    BigReal(BigReal&& another_realNumber);
    void set_RealNumber(const string &realNumber);
    BigReal& operator= (const BigReal& another_realNumber);
    BigReal& operator= (BigReal&& another_realNumber);
};


#endif //BIGREAL_BIGREAL_H
