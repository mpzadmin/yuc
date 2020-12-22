#include <iostream>
#include <string>

using namespace std;

void display(string name, size_t len);

int main()
{
    string name;

    cout << "Enter your name : ";
    getline(cin, name);

    display(name, 5);

    return 0;
}

void display(string name, size_t len)
{
    string* namePtr = &name;

    for (int index = 0; index <= len; index++)
        cout << (*namePtr)[index] << endl;
}