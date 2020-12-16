#include <iostream>
#include <string>

using namespace std;

void delay(int);

int main()
{
    string text = "Hello world!";
    for (int i = 0; i < text.length(); i++)
    {
        cout << text[i];
        delay(20);
    }
}

void delay(int delayValue)
{
    for (int index = 0; index < delayValue; index++)
    {
        for (int i = 0; i < 2000000; i++);
    }
}