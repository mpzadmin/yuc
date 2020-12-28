#include <iostream>

using namespace std;

float calculateSeries(size_t number);
size_t factorial(size_t number);

int main()
{
    int number;
    cout << "Enter a number to calculate its series: ";
    cin >> number;
    cout << "The calculation result is: " << calculateSeries(number);
}

float calculateSeries(size_t number)
{
    return (number == 1) ? number : 1/(float) factorial(number) + calculateSeries(number - 1);
}

size_t factorial(size_t number)
{
    return (number == 0) ? 1 : number * factorial(number - 1);
}