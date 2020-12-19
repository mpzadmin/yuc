#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#else 
#include <unistd>
#endif

using namespace std;

void delay(unsigned milliSeconds = 200);

int main()
{
    string text = "Good luck!";
    for (int index = 0; index < text.length(); index++)
    {
        cout << text[index];
        delay();
    }
    cout << endl;
}

void delay(unsigned milliSeconds)
{
    #ifdef _WIN32
    Sleep(milliSeconds);
    #else
    usleep(milliSeconds * 1000);
    #endif
}