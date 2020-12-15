#include <iostream>

using namespace std;

const int maxRow = 10;
const int maxColumn = 10;

int main(int argc, char const *argv[])
{
    int number;
    system("cls");
    for (int row = 1; row <= maxRow; row++)
    {
        for (int column = 1; column <= maxColumn; column++)
        {
            number = row * column;
            cout << number << "\t"; 
        }
        cout << endl << endl;        
    }
    
}
