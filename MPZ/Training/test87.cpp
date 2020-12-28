#include <iostream>

using namespace std;

size_t factorial(size_t number);

int main()
{
    size_t number = 7;
    cout << factorial(number) << endl;   
}

size_t factorial(size_t number)
{
    return (number == 1) ? number : number * factorial(number - 1);    
}