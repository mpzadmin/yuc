 #include <iostream>
#include <string>

using namespace std;

void delay(int);

int main()
{
    string name;
    cout << "Enter a name: ";
    getline (cin, name);
    
    int delayValue;
    cout << "Enter a number for delayValue: ";
    cin >> delayValue;

    for (int i = 0 ; i <= name.length() ; i++)
    {
        cout << name[i];
        delay(delayValue);
    }
}

void delay(int delayValue)
{
    for (int index = 1; index <= delayValue; index++);
}    
