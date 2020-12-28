#include <iostream>

using namespace std;

size_t factorial(size_t number);
float series(float number);

int main()
{
    size_t number = 5;
    cout << factorial(number) << endl;
    cout << series(number) << endl;
}

size_t factorial(size_t number)
{
    return (number == 1) ? number : number * factorial(number - 1);
}

float series(float number)
{
    return (number == 1) ? number : (float) (1/(float)factorial(number) + series(number - 1));
}