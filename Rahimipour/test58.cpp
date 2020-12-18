#include <iostream>
#include <string>
#include <iomanip>

const int delayValue = 35000000;

using namespace std;

void delay(int);

int main()
    
{
    string name;
    cout << "Enter sht: ";
    getline(cin, name);
    
    for (int index = 0; index < name.length(); index++)
    {
        cout << name[index];
        delay(delayValue);
    }
}
void delay(int delayValue)
{
    for (int index = 1; index <= delayValue; index++);
}