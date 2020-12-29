#include <iostream>

using namespace std;

void printNumbers(int** numbers, size_t rowCount);

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
        numbers[row] = new int [colCount+1];
        numbers[row][0] = colCount;
        for (int col=1; col<=colCount; col++)
        {
            cout << "Enter column (" << col << ") of row (" << row+1 << "): ";
            cin >> numbers[row][col];
        }
    }

    printNumbers(numbers, rowCount);

    for (int row=0; row<rowCount; row++)
    {
        delete[] numbers[row];
    }
    
    delete[] numbers;
}

void printNumbers(int** numbers, size_t rowCount)
{
    int colCount;
    for (int row=0; row<rowCount; row++)
    {        
        colCount = numbers[row][0];
        for (int col=1; col<=colCount; col++)
        {
            cout << numbers[row][col] << "\t";
        }
        cout << endl;
    }
}