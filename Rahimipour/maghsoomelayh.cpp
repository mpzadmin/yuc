#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    system("cls");

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    int number;
    SetConsoleTextAttribute(consoleHandle, 1);
    cout << "Enter a number and you'll see all it's divisor: ";
    cin >> number;
    int list[number];
    
    for (int index = 1; index <= number; index++)
    {
        if (number % index == 0)
        {
            list[index] = (number / index);
        }
    }

    for (int index = number; index >= 1; index--)
    {
        if (list[index] * index == number)
        {
            SetConsoleTextAttribute(consoleHandle, 2);
            cout << list[index] << ", ";
        }
    }
}