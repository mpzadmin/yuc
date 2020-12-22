#include <iostream>

using namespace std;

void display(string* ptr, size_t len);

int main()
{
    string name = "Ahad";
    display(&name, name.length());
}

void display(string* ptr, size_t len)
{
    for (int index = 0; index < len; index++)
    {
        cout << (*ptr)[index] << endl;
    }
}