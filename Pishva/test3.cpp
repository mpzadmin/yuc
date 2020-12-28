#include <iostream>

using namespace std;

double recursiveFunction(double number);

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
    return (number == 1) ? number : (1 / number) + recursiveFunction(number-1);
}
