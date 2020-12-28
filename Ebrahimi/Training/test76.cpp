#include <iostream>

using namespace std;

size_t factorial(size_t number);

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    try
    {
        if (number < 0)
        throw number;
    }
    catch(int value)
    {
        cout << "You should have entered a nonnegative number!" << endl;
        cout << "Your number was " << value << endl;
        return 0;
    }
    
    cout << "The factorial of " << number << " is " << factorial(number) << endl; 
} 

size_t factorial(size_t number)
{
    return (number <= 1) ? 1 : number * factorial(number - 1);
}
