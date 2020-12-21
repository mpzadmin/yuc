#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd>
#endif

using namespace std;

//Delay making
void delay(unsigned milliSecond)
{
    #ifdef _WIN32
    Sleep(milliSecond);
    #else
    usleep(milliSecond * 1000);
    #endif
}

//Printing a string by character to character delaying
void display(unsigned milliSecond, string text)
{
    for (int index = 0; index < text.length(); index++)
    {
        cout << text[index];
        delay(milliSecond);
    }
}

//Using two above functions and another variable for getting to the next line or tab
void display(unsigned milliSecond, string text, bool newLine)
{
    display(milliSecond, text);
    newLine ? cout << endl : cout << "\t";
}