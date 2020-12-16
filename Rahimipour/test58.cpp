#include <iostream>
#include <string>
#include <iomanip>

const int delay1 = 35000000;

using namespace std;

void delay()
{
    for (int index = 1; index <= 35000000; index++);
}

int main()
    
{
    string name;
    cout << "Enter sht: ";
    getline(cin, name);
    
    for (int index = 0; index < name.length(); index++)
    {
        delay();
        cout << name[index];
    }
}