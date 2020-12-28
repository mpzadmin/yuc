#include <iostream>

using namespace std;

size_t factorial(size_t number);

int main()
{
    size_t number;
    cout << "Enter a number: ";
    cin >> number;
    
    cout << "The factorial of " << number << " is " << factorial(number) << endl; 
} 

size_t factorial(size_t number)
{
    return (number <= 1) ? 1 : number * factorial(number - 1);
}
