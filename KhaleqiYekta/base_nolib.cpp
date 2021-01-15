/*
 * Copyright © {YEAR} Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file {FILENAME}.cpp
 * @brief {EXPLANATION}
 */

/** External Libraries **/
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

/** Namespaces **/
using namespace std;

/** Typedefs **/
/** Constants **/
/** Other Variables **/

/** Function Declarations **/

/**
 * Asks the user for a string, then goes to the next line.
 *
 * @param titleToPrint The text which will be shown to the user before getting the input.
 * @return User input
 */
string askForString(const string &titleToPrint);

/**
 * Asks the user for an int, then goes to the next line.
 *
 * @param titleToPrint The text which will be shown to the user before getting the input.
 * @return User input
 */
int askForInt(const string &titleToPrint);

/**
 * Clears the standard output stream (OS independent).
 */
void clearConsole();

/**
 * Pauses the standard output stream by asking the user to press any key (OS independent).
 */
void pauseConsole();

/**
 * Program's Entry Point
 */
int main()
{
    clearConsole();
    /** Start of the program **/

    /* TODO: CODE GOES HERE */

    /** End of the program **/
    pauseConsole();
    return 0;
}

/* TODO: PROGRAM FUNCTIONS GO HERE */

string askForString(const string &titleToPrint)
{
    string data;

    cout << titleToPrint;
    getline(cin, data);
    cout << endl;

    return data;
}

int askForInt(const string &titleToPrint)
{
    int data;

    cout << titleToPrint;
    cin >> data;
    cout << endl;
    cin.clear();
    cin.ignore();

    return data;
}

void clearConsole()
{ 
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void pauseConsole()
{
    #ifdef _WIN32
    system("pause");
    #else
    system("read -n1 -r -p \"Press any key to continue...\" key");
    #endif
}
