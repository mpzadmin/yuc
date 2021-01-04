#include <iostream>
#include <fstream>
#include <string>

using namespace std;

fstream file;

int main()
{
    int number;

    remove("my_umbers.dat");
    
    file.open("my_umbers.dat", ios::out | ios::app | ios::binary);    
    for (int index=1; index<=10; index++)
    {
        number = index + 1000;
        file.write((char *) &number, sizeof(number));
        if (file.fail())
        {
            cout << "ERROR!";
        }
    }
    file.close();

    system("cls");

    file.open("my_umbers.dat", ios::in | ios::binary);        
    while ( file.read((char *) &number, sizeof(number)) )
    {
        cout << number << endl;
    }
    file.close();
}