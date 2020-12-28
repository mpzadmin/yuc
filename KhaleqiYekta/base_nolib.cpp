/*
 * Copyright © TODO:{YEAR} Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 * Creation Date: TODO:{YEAR-MONTH-DAY}
 */

/** External Libraries **/
#include <iostream>
#include <string>

/** Namespaces **/
using namespace std;

/** Constants **/


/** Function Declarations **/
string askForString(const string &titleToPrint);
int askForInt(const string &titleToPrint);
void clearConsole();
void pauseConsole();

// Program's Entry Point
int main()
{
    /** Initialization Of Local Variables **/
    /* TODO: VARIABLES GO HERE */

    clearConsole();

    /* TODO: CODE GOES HERE */

    /** End of the program **/
    pauseConsole();
    return 0;
}

/* TODO: PROGRAM FUNCTIONS GO HERE */

// Returns a string which is requested from user, then goes to a new line after the process is done.
string askForString(const string &titleToPrint)
{
    string data;

    cout << titleToPrint;
    getline(cin, data);
    cout << endl;

    return data;
}

// Returns an integer which is requested from user, then goes to a new line after the process is done.
int askForInt(const string &titleToPrint)
{
    int data;

    cout << titleToPrint;
    cin >> data;
    cout << endl;

    return data;
}

// Clears the console (on any OS)
void clearConsole()
{ 
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

// Pauses the console (on any OS)
void pauseConsole()
{
    #ifdef _WIN32
    system("pause");
    #else
    system("read -n1 -r -p \"Press any key to continue...\" key");
    #endif
}
