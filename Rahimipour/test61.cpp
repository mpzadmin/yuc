#include <iostream>
#include <string>
#include <iomanip>
    
using namespace std;

bool isEven(int number);

int main()
    
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    isEven(number) ? cout << "Even" : cout << "Odd";
}

bool isEven(int number)
{
    
    bool result = false;
    if ((number % 2) == 0)
        result = true;
    return result;
    
}