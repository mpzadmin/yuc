#include <iostream>
#include <fstream>

using namespace std;

fstream file;

int fileSize();

int main()
{
    int numbers[5] = {1001, 1002, 1003, 1004, 1005};

    file.open("numbers_list.dat", ios::out | ios::binary | ios::app);
    file.write((char *) numbers, sizeof(numbers));
    cout << "File size: " << fileSize() << endl;
    file.close();


    file.open("numbers_list.dat", ios::in | ios::binary);
    while (file.read((char *) numbers, sizeof(numbers)) )
    {
        for (int number : numbers)
        {
            cout << number << endl;
        }
    }
    file.close();
}

int fileSize()
{
    file.seekg(0, ios::end);
    return file.tellg();
}