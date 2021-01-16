#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int find(string fileName, string name);

fstream File;

int main()
{
    cout << find("find_name_file.txt", "ehsan") << endl;
    cout << find("find_name_file.txt", "ali") << endl;
}

int find(string fileName, string name)
{
    int result = 0;
    string str;

    File.open(fileName, ios::in);

    while (!File.eof())
    {
        getline(File, str);
        if (str == name)
        {
            result++;
        }
    }

    return result;
}