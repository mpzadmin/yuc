#include <iostream>

using namespace std;

int myMax(int a, int b);
float myMax(float a, float b);
double myMax(double a, double b);

int main()
{        
    double number1 = 82765, number2 = 5332.77;
    cout << myMax(number1, number2);    
}

int myMax(int a, int b)
{
    int result;
    if ( a > b ) 
        result = a;
    else
        result = b;

    return result;                
}

float myMax(float a, float b)
{
    int result;
    if ( a > b ) 
        result = a;
    else
        result = b;

    return result;                
}

double myMax(double a, double b)
{
    int result;
    if ( a > b ) 
        result = a;
    else
        result = b;

    return result;                
}