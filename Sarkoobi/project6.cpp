#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void search(list<string> names, string &searchName);
typedef list<int>::iterator stringListIterator;

int main(int argc, char const *argv[])
{
    list<string> names;
    string userName;
    string searchName;
    int index = 1;
    for (string name : names)
    {
        cout << "please enter the name (" << index << ")";
        cin >> userName;
        names.push_back(userName);
        index++; 
    }
    cout << "which name do you want to search";
    cin >> searchName;
    search(names, searchName);
    return 0;
}
bool search(list<string> names, string searchName)
{
   list<string>::iterator it;
   it = find(names.begin(), names.end(), searchName);
   return (it != names.end()) ? true : false;
}
