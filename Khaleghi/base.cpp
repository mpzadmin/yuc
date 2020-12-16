#include <iostream>
#include <string.h>

using namespace std;

void delay(int delay, string text)
{
    for (int i = 0; i < text.length(); i++)
    {
        for (int j = 0; j < delay; j++);

        cout << text[i];
    }
}

int main()
{
    delay(100000000, "Hello C++ Class!");
}