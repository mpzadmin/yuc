#include <iostream>
#include <fstream>

using namespace std;

fstream file;

int main(int argc, char const *argv[])
{
    string fileName;
    string keyWord;

    cout << "Enter file name:";
    cin >> fileName; 
    cout << "Enter keyWord:";
    cin >> keyWord; 

    system("cls");
    cout << find(fileName, keyWord);
}

int find(string fileName, string keyWord)
{
    string str;
    int count = 0;

    textFile.open(fileName, ios::in);

    while ( !textFile.eof() )
    {
        getline(textFile, str);
        if(str == keyWord)
        {
            getline(textFile, str);
            cout++;
        }
    } 

    textFile.close();
    return count;
}