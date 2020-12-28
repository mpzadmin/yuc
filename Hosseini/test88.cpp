#include <iostream>

using namespace std;

float series (float number);
float factorial (float number);

int main ()
{
   cout << "sum of series for 2 = " <<  series(2) << endl;
   cout << "sum of series for 3 = " <<  series(3) << endl;
   cout << "sum of series for 5 = " <<  series(5) << endl;
}

float factorial (float number)
{
    if (number <= 1)
    {
        return number;
    }

    else return number * factorial(number - 1);
}

float series (float number)
{
    if (number == 1)
    {
        return number;
    }

    else return (1 / factorial(number)) + series(number - 1);
}
