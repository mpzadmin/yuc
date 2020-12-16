/*
 *  Print Animator Program
 * 
 *  By: YektaDev [Ali Khaleqi Yekta]
 *  Website: Yekta.Dev
 *  Email: Me@Yekta.Dev
 */


// External Libraries
#include <iostream>
#include <string>

// Namespaces
using namespace std;

// Constants
const int delayValue = 50;
const string textToPrint = "Hello C++ Class!";

// Function Declrations
void clearConsole();
void delay(int delay = 10);

// Program's Entry Point
int main()
{
    clearConsole();

    for (int i = 0; i < textToPrint.length(); i++)
    {
        delay(delayValue);

        cout << textToPrint[i];
    }
}

// Block the thread for some time
void delay(int delay)
{ 
    for (int i = 0; i < 1000000; i++)
    {
        for (int j = 0; j < delay; j++);
    }
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
