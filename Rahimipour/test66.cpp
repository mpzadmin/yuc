#include <iostream>

using namespace std;

void display(string name);

int main()
{
    display("Ahad");
}

void display(string name)
{
    string *ptr = &name;
    for (int index = 0; index < name.length(); index++)
    {
        cout << (*ptr)[index] << endl;
    }
}