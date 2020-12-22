#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd>
#endif

using namespace std;

void delay(unsigned milliSecond = 100);
void display(unsigned milliSecond, string text);
void display(unsigned milliSecond, string text, bool newLine);

int main()
{
    display(100, "hello world!", true);
    display(50, "Good luck!", false);
    delay();
    display(20, "Welcome to C++ programming!", true);
    display(100, "Good bye!", true);
}

void delay(unsigned milliSecond)
{
    #ifdef _WIN32
    Sleep(milliSecond);
    #else
    usleep(milliSecond * 1000);
    #endif
}

void display(unsigned milliSecond, string text)
{
    for (int index = 0; index < text.length(); index++)
    {
        cout << text[index];
        delay(milliSecond);
    }
}

void display(unsigned milliSecond, string text, bool newLine)
{
    display(milliSecond, text);
    newLine ? cout << endl : cout << "\t";
}