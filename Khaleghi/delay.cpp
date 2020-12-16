#include <iostream>
#include <string.h>

using namespace std;

const int delayValue = 50;
const string textToPrint = "Hello C++ Class!";

void delay(int);

int main()
{
    for (int i = 0; i < textToPrint.length(); i++)
    {
        delay(delayValue);

        cout << textToPrint[i];
    }
}

void delay(int delay)
{ 
    for (int i = 0; i < 1000000; i++)
    {
        for (int j = 0; j < delay; j++);
    }
}
