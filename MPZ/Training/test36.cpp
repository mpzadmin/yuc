#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name = "Masoud";

    cout << name[name.length()-1];

    cout << "Enter your name: ";
    getline(cin, name);
    for (int index = name.length()-1; index >= 0 ; index--)
    {        
        cout << name[index];        
    }

}