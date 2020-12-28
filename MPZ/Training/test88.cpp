#include <iostream>

using namespace std;

size_t factorial(size_t number);
float mySeries(float number);

int main()
{
    size_t number = 4;
    cout << "The factorial is: " << factorial(number) << endl;   
    cout << "The series result is: " << mySeries(number);
}

size_t factorial(size_t number)
{
    return (number <= 1) ? number : number * factorial(number - 1);
}

float mySeries(float number)
{
    return (number == 1) ? number : (float) ((1/(float) factorial(number)) + mySeries(number - 1));
}