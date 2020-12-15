#include <iostream>

using namespace std;

const int maxRow = 8;
const int maxCol = 8;

int main()
{
    char matrix[8][8];
    char myChar = '*';

    for (int row = 0; row < maxRow; row++)
    {
        if ((row % 2) == 0)
        {
            myChar = '*';
        } else {
            myChar = 'X';            
        }
     
        for (int col = 0; col < maxCol; col++)
        {            
            matrix[row][col] = myChar;
            if (myChar == '*')
            {
                myChar = 'X';
            }
            else
            {
                myChar = '*';
            }
        }
    }

    for (int row = 0; row < maxRow; row++)
    {
        for (int col = 0; col < maxCol; col++)
        {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }


}