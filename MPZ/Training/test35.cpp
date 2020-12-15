#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    for (int index = 0; index < name.length(); index++)
    {
        if ( name[index] != ' ' ) {
            cout << name[index] << endl;
        }
    }

}