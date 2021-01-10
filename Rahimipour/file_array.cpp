#include <iostream>
#include <string>
#include <fstream>
using namespace std;

fstream file;

int main()
{
    int list[] = {1, 2, 3, 4, 5};
    file.open("file_array.txt", ios::out | ios::app);
    
    file.write((char *) &list, sizeof(list));

    file.close();

    file.open("file_array.txt", ios::in);
    
    file.read((char *) &list, sizeof(list));
    for (int number : list)
    {
        cout << number << endl;
    }

    file.close();
}