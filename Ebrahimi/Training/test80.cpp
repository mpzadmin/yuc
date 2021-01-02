#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

bool nameSearch(list<string> names, string name);

int main()
{
    list<string> names;
    size_t count;
    string tempName, name;

    cout << "Enter count of names: ";
    cin >> count;

    for (int index = 0; index < count; index++)
    {
        cout << "Enter name(" << index+1 << "): ";
        cin >> tempName;
        names.push_back(tempName);
    }

    cout << "Enter a name for finding if it's in your list: ";
    cin >> name;

    if (nameSearch(names, name))
    {
        cout << "FOUND" << endl;
    }
    else
    {
        cout << "NOT FOUND" << endl;
    }
}

bool nameSearch(list<string> names, string name)
{
    list<string>::iterator it;
    it = find(names.begin(), names.end(), name);
    return (it != names.end()) ? true : false;
}