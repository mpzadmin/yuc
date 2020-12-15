#include <iostream>

using namespace std;

const int maxList = 100;

int main()
{
    int list[maxList];
    int count;

    cout << "Enter count of numbers: ";
    cin >> count;

    for (int index = 0; index < count; index++)
    {
        cout << "Enter the number[" << (index + 1) << "]: ";
        cin >> list[index];
    }

    cout << "The numbers from last to first are: " << endl;
    for (int index = count-1; index >= 0; index--)
    {
        cout << "\t" << list[index];
    }
}