#include <iostream>
using namespace std ;
int multiply(int dig)
{
     int dig1 = dig%10;
     int dig2 = (dig%100) /10;
    int result = dig1 * dig2 ;
         return result;
}
bool bears_picnic(int n )
{
    if (n == 42)
    {
        return true;
    }
    if (n <42)
    {
        return false; 
    }
    if (n%2 == 0 && bears_picnic(n/2))
    {
        return true;
    }
    if (n%5 == 0 && bears_picnic(n-42))
    {
        return true;
    }
    if ( n%3 ==0 || n%4 == 0 && bears_picnic(n - multiply(n)))
    {
        return true;
    }
}
int main()
{
cout<<boolalpha<<bears_picnic(5);
}