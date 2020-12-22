#include <iostream>

using namespace std;

int main()
{
    int** numbers;
    int rowCount, colCount; // we wanna take two numbers

    system("cls");
    cout << "Enter count of rows: ";
    cin >> rowCount;

    numbers = new int* [rowCount];
    for (int row = 0; row < rowCount; row++)
    {
        // we have * numbers
        cout << "";
    }
}