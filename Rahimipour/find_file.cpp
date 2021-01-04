#include <iostream>
#include <string>
#include <fstream>

using namespace std;

fstream fileName;
int findWord(string names, string wordSearch);

int main()
{
    system("cls");
    string names, wordSearch;
    cout << "Enter the file name: ";
    getline(cin, names);
    cout << "Enter the word that you wanna find: ";
    getline(cin, wordSearch);
    system("cls");

    cout << "word ( " << wordSearch << " ) has repaeted [ " << findWord(names, wordSearch) << " ] times.";

}

int findWord(string names, string wordSearch)
{
    string name;
    int counter = 0;
    fileName.open(names, ios::in);
    
    while (getline(fileName, name))
    {
        if (name == wordSearch)
        {
            counter += 1;
        }
    }
    fileName.close();
    return counter;
}