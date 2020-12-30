#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

bool searchName(list<string> names, string name);

int main()
{
    list<string> names;

    if ( searchName(names, "ali") )
    {
        cout << "FOUND";
    }
    else
    {
        cout << "NOT FOUND";
    }
    

}

bool searchName(list<string> names, string name)
{
    list<string>::iterator it;
    it = find(names.begin(), names.end(), name);
    return (it != names.end()) ? true : false;
}