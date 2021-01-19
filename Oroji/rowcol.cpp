#include <iostream>
#include <string>
using namespace std;

int main()
{

}
void printNumbers(int** numbers,size_t rowCount , size_t colCount )
{
system("cls");
cout << "enter row: " << endl;
cin >> rowCount;
numbers = new int* [rowCount];
for(int row=0 ; row<rowCount ; row++) 
    {
        cout << "enter column of row ("<< row+1 <<"): ";
        cin >> colCount;
        numbers[row] = new int [colCount];
       for(int col=0 ; col<colCount ; col++)  
       {
           cout << "enter column ("<< col+1 <<") enter row ("<< row+1 <<"): ";
           cin >> numbers[row][col];
       }
    }

} 