#include <iostream>
#include <fstream>

using namespace std;

fstream file;
size_t findWord(string adress, string word);

int main()
{
    string fileAdress, word;
    
    cout << "Enter the adress of file: ";
    cin >>  fileAdress;
    cout << "Enter a word you want to search: ";
    cin >> word;
    cout << word << " found in " << fileAdress << " " << findWord(fileAdress, word) << " times." << endl;
}

size_t findWord(string adress, string word)
{
    string name;
    size_t count = 0;
    file.open(adress, ios::in);
    while (getline(file, name))
    {
        if (name == word) count++;
    }
    file.close();
    return count;
}