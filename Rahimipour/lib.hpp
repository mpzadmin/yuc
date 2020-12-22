#include <iostream>
#include <string>

using namespace std;

// Display starting
void display(string str)
{
    cout << str;
}

void display(string str, bool newLine)
{
    display(str); // to prevent repeating 
    if (newLine)
    {
        cout << endl;
    }
}

void delay(int delayValue)
{
    for (int index = 1; index <= delayValue; index++);
}