#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 deque<int> result;
    void binaryPrint(int n){
    if (n>1)
    {
            result.push_front(n%2);
            binaryPrint(n/2);
    }
    if (n==1)
    {
        result.push_front(1);
    }
    else if(n==0)
    {
            result.push_front(0);
            return;
    }

    }



int main ()
{
    int number;
    cout<<"Enter a number :";
    cin>> number;
    binaryPrint(number);

    for (int i ;i <result.size(); i++)
    {
        cout<<result[i];
    }


}

