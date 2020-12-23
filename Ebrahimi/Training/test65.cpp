#include <iostream>
#include <string>

using namespace std;

void display(string* text, size_t len);

int main()
{
    string name = "Matin";
    display(&name, name.length()); 
}

void display(string* text, size_t len)
{
    for (int index = 0; index < len; index++)
    {
        cout << (*text)[index] << endl;
    }
}