#include <iostream>
#include <string>

using namespace std;

void delay(int delayValue = 50);

int main()
{
    string text = "Hello world!";
    for (int index = 0; index < text.length(); index++)
    {
        cout << text[index];
        delay();
    }
}

void delay(int delayValue)
{
    for (int index = 0; index < delayValue; index++)
    {
        for(int counter=0; counter < 1000000; counter++);
    }
}