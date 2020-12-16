#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif 

using namespace std;

void delay(unsigned milliseconds = 100);

int main()
{
    string text = "Hello world!";
    for (int index = 0; index < text.length(); index++)
    {
        cout << text[index];
        delay();
    }    
}

void delay(unsigned milliseconds)
{
    #ifdef _WIN32
    Sleep(milliseconds);
    #else
    usleep(milliseconds*1000);
    #endif
}