#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif 

using namespace std;

// Display a string
void display(string str)
{
    cout << str;
}

// Display a string and add endl
void display(string str, bool newLine)
{
    display(str);
    if (newLine)
    {
        cout << endl;
    }
}

// Make a delay
void delay(unsigned milliseconds)
{
    #ifdef _WIN32
    Sleep(milliseconds);
    #else
    usleep(milliseconds*1000);
    #endif
}