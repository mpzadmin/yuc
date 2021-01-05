#include <iostream>
#include <fstream>

using namespace std;

fstream file;

int main()
{
    char myChars[] = {'M', 'a', 't', 'i', 'n', '\0'};

    file.open("test87.dat", ios::out | ios::binary);
    if (file.is_open() != 1)
    {
        cerr << "Error in opening the file!" << endl;
        return 0;
    }

    file.write((char *) myChars, sizeof(myChars));
    if (file.fail() == 1)
    {
        cerr << "Error in putting data to the file!" << endl;
        return 0; 
    }
    file.close();

    file.open("test87.dat", ios::in | ios::binary);
    if (file.is_open() != 1)
    {
        cerr << "Error in opening the file!" << endl;
        return 0;
    }
    file.read((char *) myChars, sizeof(myChars));
    if (file.fail() == 1)
    {
        perror("Error in taking data of the file!");
        return 0;
    }
    cout << myChars << endl;
    file.close();
}