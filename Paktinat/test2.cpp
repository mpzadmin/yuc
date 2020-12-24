#include <iostream>

using namespace std;

int main ()
{
    int number, factorial;
    cout << "enter a number : ";
    cin >> number;
    for (int i=1; i <= number; i++)
    {
        factorial *= number-1;
    }
    cout << factorial;
}