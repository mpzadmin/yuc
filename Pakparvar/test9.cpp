#include <iostream>
#include <fstream>
#include <string>
using namespace std;
fstream file;
int main()
{
    remove("my_umbers.dat");
    system("cls");
    int number;
    file.open("my_umbers.dat", ios::out | ios::binary);
    number = 1234567890;
    file.write((char *)&number , sizeof(number));

    file.close();

    
}