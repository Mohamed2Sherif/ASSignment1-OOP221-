#include<iostream>
#include "BigDecimalInt.h"
using namespace std;

int main(){
    string s,v;
    cin>>s>>v;
    BigDecimalInt x(s);
    BigDecimalInt y(v);
    if(x < y){
        cout<<"oh yah my code is legendary";
    }

    else
        cout<<"haha it is bug";
}