#include <iostream>
#include <fstream>
#include <string>

using namespace std;

fstream file;

int find(string fileName, string keyWord);

int main(int argc, char const *argv[])
{
    int result;
    string fileName;
    string keyWord;

    cout << "Enter file name:";
    cin >> fileName; 
    cout << "Enter keyWord:";
    cin >> keyWord; 

    system("cls");
    result = find(fileName, keyWord);
    if(result == -1)
        cerr << "Cant open the file";
    else
        cout << "count of name (" << keyWord << "):" << find(fileName, keyWord);
}

int find(string fileName, string keyWord)
{
    string str;
    int count = 0;

    file.open(fileName, ios::in);

    if(file.fail())
        return -1;
    
    while ( !file.eof() )
    {
        getline(file, str);
        if(str == keyWord)
        {
            getline(file, str);
            count++;
        }
    } 

    file.close();
    return count;
}