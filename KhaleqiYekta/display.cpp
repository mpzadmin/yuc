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
#include "console.hpp"

// Namespaces
using namespace std;

// Function Declrations
void display(string str);
void display(string str, bool newLine);

// Program's Entry Point
int main()
{
    clearConsole();

    display("Hello World!", true);
    display("Hello Class!", false);
    display("Hello Teacher!");
}

// Display a text to user
void display(string str)
{
    cout << str;
}

// Display a text to user
void display(string str, bool newLine)
{
    display(str);

    if (newLine)
    {
        cout << endl;
    }
}
