#include <iostream>
#include <fstream>
#include <string>

using namespace std;

fstream file;

int main()
{
    float number = 10;

    file.open("test85.dat", ios::out | ios::binary);
    if (file.is_open() != 1)
    {
        perror("Error in opening the file!");
        return 0;
    }
 
    for (int index = 1; index <= 10; index++)
    {
        number++;
        file.write((char *) &number, sizeof(number));

        if (file.fail() == 1)
        {
            perror("Error in putting data to the file!");
            return 0;
        }
    }
    file.close();

    file.open("test85.dat", ios::in | ios::binary);
    while ( file.read((char *) &number, sizeof(number)) )
    {
        if (file.fail() == 1)
        {
            perror("Error in taking data of the file!");
            return 0;
        }

        cout << number << endl;
    }
    file.close();
}