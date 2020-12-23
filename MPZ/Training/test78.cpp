#include <iostream>

using namespace std;

void printNumbers(int** numbers, size_t rowCount, size_t colCount);

int main()
{
    int** numbers;
    int rowCount, colCount;

    system("cls");
    cout << "Enter count of rows: ";
    cin >> rowCount;

    numbers = new int* [rowCount];
    for (int row=0; row<rowCount; row++)
    {
        cout << "Enter count of columns of row (" << row+1 << "): ";
        cin >> colCount;
        numbers[row] = new int [colCount];
        for (int col=0; col<colCount; col++)
        {
            cout << "Enter column (" << col+1 << ") of row (" << row+1 << "): ";
            cin >> numbers[row][col];
        }
    }

    printNumbers(numbers, rowCount, colCount);

    for (int row=0; row<rowCount; row++)
    {
        delete[] numbers[row];
    }
    
    delete[] numbers;
}

void printNumbers(int** numbers, size_t rowCount, size_t colCount)
{
    for (int row=0; row<rowCount; row++)
    {        
        for (int col=0; col<colCount; col++)
        {
            cout << numbers[row][col] << "\t";
        }
        cout << endl;
    }
}