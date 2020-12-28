#include <iostream>

using namespace std;

float calculateSeries(float number);
float factorial(float number);

int main()
{
    cout << calculateSeries(4);
}

float calculateSeries(float number)
{
    return (number == 1) ? number : 1/factorial(number) + calculateSeries(number - 1);
}

float factorial(float number)
{
    return (number == 0) ? 1 : number * factorial(number - 1);
}