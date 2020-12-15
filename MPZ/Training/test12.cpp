#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    float number1, number2, number3;
    float average;

    system("cls");

    cout << "Enter 3 numbers: ";
    cin >> number1 >> number2 >> number3;
    average = (number1 + number2 + number3) / 3;
    cout << "The average is " << average;

    return 0;
}
