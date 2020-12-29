#include <iostream>

using namespace std;

size_t factorial(size_t number);
float mytest(float number);

int main()
{
    size_t number = 3;
    cout << "the test result is: " << mytest(number) << endl;
}

size_t factorial(size_t number)
{
    return (number <= 1) ? number : number * factorial(number - 1);
}

float mytest(float number)
{
    return (number==1) ? number  : (float)((1/(float)factorial(number)) + mytest(number - 1));
}



