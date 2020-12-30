#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int count;
    string tempname, nameKey;
    list<string> names;
    for (size_t i = 1; i <= count; i++)
    {
        cout << "Enter name (" << i << "):";
        cin >> tempname;
        names.push_back(tempname);
    }
    
    cout << "Enter name key:";
    cin >> nameKey;
    cout << findList(names, nameKey);
}

bool findList(list<string> names,name)
{
    for (list<string>::iterator index=numbers.begin(); index!=numbers.end(); index++)
    {
        if(*index == name)
            return true;
    }
    return false;
}