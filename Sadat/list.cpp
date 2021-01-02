#include <iostream>
#include <list>

using namespace std;

bool searchlist(list<string> names, string search);

int main()
{
    list<string> names;
    string temp, search;
    bool searchResult;

    while(true)
    {
        cout << "Enter name that you want add to list or enter q to end the list." << endl;
        cin >> temp;
        if (temp == "q") break;
        names.push_back(temp);
    }

    cout << "Enter a name to search for: ";
    cin >> search;
    searchResult = searchlist(names, search);
    if (searchResult)
    {
        cout << "FOUND";
    }
    else
    {
        cout << "NOT FOUND!";
    }
    

}

bool searchlist(list<string> names, string search)
{
    for (string name : names)
    {
        if (name == search) return true;
    }
    return false;
}