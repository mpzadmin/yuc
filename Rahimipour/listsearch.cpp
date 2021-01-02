#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

bool searchName(list<string> names, string name);

int main()
{
    list<string> names;
    string main, name;

    cout << "Enter something: ";
    getline(cin, main);
    names.push_back(main);

    cout << "Enter the word that you want to be searched: ";
    cin >> name;

    

    if (searchName(names, name))
    {
        cout << "FOUND" << endl;
    }

    else 
    {
        cout << "NOT FOUND" << endl;
    }

}

bool searchName(list<string> names, string name)
{
    list<string>::iterator it;
    it = find(names.begin(), names.end(), name);

    return (it != names.end()) ? true : false;
}