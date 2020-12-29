#include <iostream>

using namespace std;

double recursiveFunction(double number);
size_t factorial(size_t number);

int main()
{
    double number;

    cout << "Enter a number: ";
    cin >> number;

    cout << recursiveFunction(number) << endl;

    return 0;
}

double recursiveFunction(double number)
{
    return (number == 1) ? number : (double) ((1 / factorial(number)) + recursiveFunction(number-1));
}

size_t factorial(size_t number)
{
    return (number == 1) ? number : number * factorial(number-1);
}