#include <iostream>

using namespace std;

size_t factorial(size_t number);
float series(float number);

int main()
{
    size_t number;
    cout << "Enter a positive number: ";
    cin >> number;

    cout << "The series result for n = " << number << " is " << series(number) << endl;
}

size_t factorial(size_t number)
{
    return (number == 1) ? 1 : number * factorial(number - 1);
}

float series(float number)
{
    return (number == 1) ? number : (1/(float) factorial(number)) + series(number - 1);  
}