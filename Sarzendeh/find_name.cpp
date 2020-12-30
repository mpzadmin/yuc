#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void findName(list<string> names, string name);

int main()
{
    int count;
    cout << "Enter a count of names: ";
    cin >> count;

    list<string> names;
    string tempName;

    for (int index=1; index <= count; index++)
    {
        cout << "Enter name(" << index << "): "; 
        cin >> tempName;
        names.push_back(tempName);
    }

    string name;
    cout << "Enter a name to find in names list: ";
    cin >> name;

    findName(names, name);
}

void findName(list<string> names, string name)
{
    list<string>::iterator it;
    it = find(names.begin(), names.end(), name);

    if (it != names.end())
        cout << "True";
    else
        cout << "False";
}