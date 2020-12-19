#include <iostream>
#include <string>

using namespace std;

void delay(int);

int main()
{
    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    for (int index = 0; index < name.length(); index++)
    {
        cout << name[index];
        delay(20);
    }
}
void delay(int delay)
{ 
    for (int i = 0; i < 1000000; i++)
    {
        for (int j = 0; j < delay; j++);
    }
}