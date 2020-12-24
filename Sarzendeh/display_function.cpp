#include <iostream>
#include <string>

using namespace std;

void display(string* name, size_t length);

int main()
{
    string name = "Ehsan";
    display (&name, name.length());
}

void display(string* name, size_t length)
{
    for (int i = 0; i < length; i++)
    {
        cout << (*name)[i] << endl;
    }
}