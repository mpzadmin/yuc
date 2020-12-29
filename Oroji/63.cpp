#include <iostream>

using namespace std;
size_t factorial(size_t number);
float sum(size_t number);
int main()
{   
    float number=3;
   cout << (float)sum(number);
    return 0;
}
size_t factorial(size_t number)
{    int sum;   
     return (number >= 1) ? number : number * factorial(number - 1);
}
float sum(size_t number)
{
    return( number>=1 ) ? 1 : 1/factorial(number)+1/factorial(number - 1);
}