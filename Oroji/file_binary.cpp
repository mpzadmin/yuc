#include <iostream>
#include <fstream>
#include <string>

using namespace std;

fstream file;
int main()
{
    int number;
    remove("number.dat");
    file.open("number.dat", ios::out | ios::app) ;
    for (int i=0; i< 5; i++)
    {
         number=i;
         file.write((char *) &number, sizeof(number));
    }
    file.close();
    file.open("number.dat", ios::in) ;
    while ( file.read((char *) &number, sizeof(number)))
    {
        cout << number << "\t";
    }
    file.close();
}