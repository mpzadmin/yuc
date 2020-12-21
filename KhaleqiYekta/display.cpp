/*
 *  @brief Text Display Program
 * 
 *  @author YektaDev [Ali Khaleqi Yekta]
 *  Website: Yekta.Dev
 *  Email: Me@Yekta.Dev
 */

/** External Libraries **/
#include <iostream>
#include <string>
#include "console.hpp"

/** Namespaces **/
using namespace std;

/** Function Declrations **/
void display(string str);
void display(string str, bool newLine);

// Program's Entry Point
int main()
{
    clearConsole();

    // Test cases
    display("Hello World!", true);
    display("Hello Class!", false);
    display("Hello Teacher!");

    return 0;
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
