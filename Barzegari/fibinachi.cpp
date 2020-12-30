#include <iostream>

using namespace std;

size_t factorial(size_t number);
float fibinachi(float number);

int main(int argc, char const *argv[])
{
    int count;

    cout << "Enter count number : ";
    cin >> count;

    cout << fibinachi(count);
}

float fibinachi(float number)
{
    return (number == 1) ? number : 1/(float)factorial(number) + fibinachi(number-1);
}

size_t factorial(size_t number)
{
    return (number == 0) ? 1 : number * factorial(number - 1);    
}