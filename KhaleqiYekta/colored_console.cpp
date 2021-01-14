/*
 *  Colored Console Program
 * 
 *  By: YektaDev [Ali Khaleqi Yekta]
 *  Website: Yekta.Dev
 *  Email: Me@Yekta.Dev
 */

// External Libraries
#include <iostream>
#include <string>
#include <windows.h>

// Namespaces
using namespace std;

// Constants
const int color1 = 2;
const int color2 = 3;
const int color3 = 6;
const int color4 = 12;
const string output1 = "Lorem ipsum dolor sit amet, ";
const string output2 = "consectetur adipiscing elit, ";
const string output3 = "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. ";
const string output4 = "Ut enim ad minim veniam.";

// Function Declrations
void setColor(int colorCode);
void clearConsole();

// Program's Entry Point
int main()
{
    clearConsole();

    setColor(color1);
    cout << output1;

    setColor(color2);
    cout << output2;

    setColor(color3);
    cout << output3;

    setColor(color4);
    cout << output4;

    // Return To White Foreground Color
    setColor(7);
}

// Set Console Color
void setColor(int colorCode)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    
    SetConsoleTextAttribute(consoleHandle, colorCode);  
}

// Clear the console (on any OS)
void clearConsole()
{ 
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}
