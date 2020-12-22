#include <iostream>

using namespace std;

int main()
{
    int** number;
    int rowCount = 10, columnCount = 10;
    
    number = new int*[rowCount];
    for (int i = 1; i <= columnCount; i++)
    {
        number[i-1] = new int[i];
        for (int j = 0; j < i; j++)
        {
            number[j] = 0;
        }
    }
    for (int i = 1; i <= columnCount; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << number[j] << " ";
        }
        cout << endl;
    }
    delete []number;
}