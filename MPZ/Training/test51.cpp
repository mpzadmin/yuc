#include <iostream>

using namespace std;

const int maxList = 100;

int main()
{
    int list[maxList];
    int number;
    int count;

    cout << "Enter count of numbers: ";
    cin >> count;

    for (int index = 0; index < count; index++)
    {
        cout << "Enter the number[" << (index + 1) << "]: ";
        cin >> list[index];
    }

    // sort array
    for (int i = 0; i < count-1; i++)
    {
        for (int j = i+1; j < count; j++)
        {
            if (list[i] > list[j])
            {
                number = list[i];   // left cell to number
                list[i] = list[j];  // right cell to left cell
                list[j] = number;   // number to left cell
            }
        }
    }

    /*
    for (int i = 0; i < count-1; i++)
        for (int j = i+1; j < count; j++)
            if (list[i] > list[j])
            {
                number = list[i];   // left cell to number
                list[i] = list[j];  // right cell to left cell
                list[j] = number;   // number to left cell
            }
    */

    cout << "The sorted numbers are: " << endl;
    for (int index = 0; index < count; index++)
    {
        cout << list[index] << "\t";
    }
}