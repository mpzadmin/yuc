#include <iostream>
#include <windows.h>

using namespace std;

const int yellowOnRedColor = 70; 
int main()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    
    SetConsoleTextAttribute(consoleHandle, yellowOnRedColor);  
    cout << "Welcome to C++" << endl;
    
    /*
    for (int index = 1; index <= 255; index++)
    {
        SetConsoleTextAttribute(consoleHandle, index);  // red on black
        cout << index << "\tWelcome to C++" << endl;
    }
    */
    
}