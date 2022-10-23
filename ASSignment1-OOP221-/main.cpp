#include<iostream>
#include "BigDecimalInt.h"
using namespace std;

int main(){
    string s,v;
    cin>>s>>v;
    BigDecimalInt x(s);
    BigDecimalInt y(v);
    BigDecimalInt result =x-y;
    cout<<result;
}