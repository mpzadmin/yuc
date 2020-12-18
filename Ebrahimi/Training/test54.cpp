#include <iostream>
#include <string>

using namespace std;

void delay(unsigned delayValue = 30);

int main()
{
    string text = "Welcome to C++!";
    for (int index = 0; index < text.length(); index++)
    {
        cout << text[index];
        delay();
    }
    cout << "\n";
}

void delay(unsigned delayValue)
{
    for (int index = 1; index < delayValue; index++)
    {
        for (int counter = 1; counter < 1000000; counter++);
    }
}