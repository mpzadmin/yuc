#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int number, factorial = 1;

    system("cls");
    cout << "Enter a number: ";
    cin >> number;
    /*
    for (int index = 2; index <= number; index++)
    {
        factorial *= index;
    }
    */

    for (int index = 2; index <= number; factorial *= index, index++);

    cout << "The factorial for " << number << " is " << factorial << endl; 

    return 0;
}
