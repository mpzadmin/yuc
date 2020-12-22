#include <iostream>
#include <string>

using namespace std;

void display(string name);

int main()
{
    string name;

    cout << "Enter your name : ";
    getline(cin, name);

    display(name);

    return 0;
}

void display(string name)
{
    string* namePtr = &name;

    for (int index = 0; index <= (name.size() - 1); index++)
        cout << (*namePtr)[index] << endl;
}