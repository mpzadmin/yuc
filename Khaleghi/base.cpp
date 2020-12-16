/*
 *  [PROGRAM NAME]
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
const string defaultStringRequestTitle = "Please enter a text: ";
const string defaultIntRequestTitle = "Please enter a number: ";

// Function Declrations
void clearConsole();
string askForString(string titleToPrint = defaultStringRequestTitle);
int askForInt(string titleToPrint = defaultIntRequestTitle);

// Program's Entry Point
int main()
{
    clearConsole();

    /* CODE GOES HERE */
}

/* PROGRAM FUNCTIONS GO HERE */

// Clear the console (on any OS)
void clearConsole()
{ 
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

// Return a string which is requested from user, then goes to a new line after the procces is done.
string askForString(string titleToPrint = defaultStringRequestTitle)
{
    string data;

    cout << titleToPrint;
    getline(cin, data);
    cout << endl;

    return data;
}

// Return an integer which is requested from user, then goes to a new line after the procces is done.
int askForInt(string titleToPrint = defaultIntRequestTitle)
{
    int data;

    cout << titleToPrint;
    cin >> data;
    cout << endl;

    return data;
}
