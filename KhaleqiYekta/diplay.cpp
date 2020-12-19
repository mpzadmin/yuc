/*
 *  Text Display Program
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

// Function Declrations
void clearConsole();
void display(string str);
void display(string str, bool newLine);

// Program's Entry Point
int main()
{
    clearConsole();

    display("Hello World!",true);
    display("Hello Class!");
    display("Hello Teacher!");
}

void display(string str)
{
    cout << str;
}

void display(string str, bool newLine)
{
    display(str);

    if (newLine)
    {
        cout << endl;
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
