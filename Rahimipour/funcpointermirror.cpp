#include <iostream>

using namespace std;

void mirror(int &number, int* &list);

int main()
{
    system("cls");

    int number;
    int* list;
    // int* list = &number;
    cout << "Enter a number: ";
    cin >> number;
    list = new int [number];
    system("cls");

    for (int index = 0; index < number; index++)
    {
        cout << "Enter number [" << index + 1 << "] : ";
        cin >> list[index]; 
    }
    mirror(number, list);
    delete[] list;
}

void mirror(int &number, int* &list)
{
    for (int index = number - 1; index >= 0; index--)
    {
        cout << list[index] << "\t";
    }
}

