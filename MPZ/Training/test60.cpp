#include <iostream>

using namespace std;

int max(int a, int b);
bool isEven(int number);
bool isOdd(int number);

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    isEven(number) ? cout << "Even" : cout << "Odd";
}

int max(int a, int b)
{
    int result;
    if ( a > b ) 
        result = a;
    else
        result = b;

    return result;                
}

bool isEven(int number)
{
    bool result = false;    
    if ( (number % 2) == 0 )
        result = true;

    return result;    
}

bool isOdd(int number)
{
    bool result = false;    
    if ( (number % 2) != 0 )
        result = true;
        
    return result;    
}