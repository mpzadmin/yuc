#include <iostream>
#include <string>
#include <iomanip>
    
using namespace std;

void printNumbers(int* numbers, size_t len);

int main()   
{
    int* numbers;
    int count;

    system("cls");
    cout << "Enter a number: ";
    cin >> count;

    numbers = new int[count];
    for (int index = 0; index < count; index++)
    {
        cout << "Enter number (" << index + 1 << ") :";
        cin >> numbers[index];
    }
    printNumbers(numbers, count);
    delete[] numbers;
}
void printNumbers(int* numbers, size_t len) // we could use int len
{
    for (int index = 0; index < len; index++)
    {
        cout << numbers[index] << "\t";
    }
}
