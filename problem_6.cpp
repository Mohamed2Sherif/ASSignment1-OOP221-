//
// Created by AHMED on 10/13/2022.
//
#include<bits/stdc++.h>
using namespace std ;
static void pattern(int n, int i);
int main(){
    pattern(4, 0) ;
    return 0 ;
}
static void pattern(int n, int i){
    if(n==2){
        for(int j=0;j<i;j++){
            cout<<' ' ;
        }
        cout<<"*"<<endl ;
        for(int j=0;j<i;j++){
            cout<<' ' ;
        }
        cout<<"* "<<"*"<<endl ;
        for(int j=0;j<i;j++){
            cout<<' ' ;
        }
        cout<<"  *"<<endl ;
    }
    else {
        pattern(n/2,i);
        for(int j=0;j<i;j++) {
            cout << ' ';
        }
        for(int j=0;j<n;j++){
            cout<<"* " ;
        }
        cout<<endl ;
        pattern(n/2,i+n) ;
    }
}