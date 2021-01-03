/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file console.hpp
 * @brief A library containing functions that are related to the standard output stream (console) environment.
 */

/** External Libraries **/
#include <iostream>
#include <string>

/** Namespaces **/
using namespace std;

/** Constants **/
const string defaultStringRequestTitle = "Please enter a text: ";
const string defaultIntRequestTitle = "Please enter a number: ";

/** Function Declarations **/

/**
 * Writes a string to the standard output stream.
 *
 * @param str The string which will be written to the console.
 */
void print(const string &str);

/**
 * Goes to the next line.
 */
void newLine();

/**
 * Writes a string to the standard output stream, then goes to the next line.
 *
 * @param str The string which will be written to the console.
 */
void printLine(const string &str);

/**
 * Writes a separator line to the standard output stream, then goes to the next line.
 *
 * @param separator The separator character which is used to draw a line with.
 * @param len Length of the line.
 */
void printSeparatorLine(const char &separator, const size_t &len);

/**
 * Asks the user for a string, then goes to the next line.
 *
 * @return User input
 */
string askForString(const string &titleToPrint = defaultStringRequestTitle);

/**
 * Asks the user for an integer, then goes to the next line.
 *
 * @return User input
 */
int askForInt(const string &titleToPrint = defaultIntRequestTitle);

/**
 * Asks the user for a float, then goes to the next line.
 *
 * @return User input
 */
float askForFloat(const string &titleToPrint = defaultIntRequestTitle);

/**
 * Clears the standard output stream (OS independent).
 */
void clearConsole();

/**
 * Pauses the standard output stream by asking the user to press any key (OS independent).
 */
void pauseConsole();

// Prints a text.
void print(const string &str)
{
    cout << str;
}

// Prints a new line.
void newLine()
{
    cout << endl;
}

// Prints a text and a new line.
void printLine(const string &str)
{
    print(str);
    newLine();
}

// Prints a separator line and a new line.
void printSeparatorLine(const char &separator, const size_t &len)
{
    string separatorLine;

    for (size_t i = 0; i < len; ++i)
    {
        separatorLine += separator;
    }

    printLine(separatorLine);
}

// Asks the user for a string, then goes to a new line.
string askForString(const string &titleToPrint)
{
    string data;

    print(titleToPrint);
    getline(cin, data);
    newLine();

    return data;
}

// Asks the user for an integer, then goes to a new line.
int askForInt(const string &titleToPrint)
{
    int data;

    print(titleToPrint);
    cin >> data;
    newLine();

    return data;
}

// Asks the user for a float, then goes to a new line.
float askForFloat(const string &titleToPrint)
{
    float data;

    print(titleToPrint);
    cin >> data;
    newLine();

    return data;
}

// Clears the console.
void clearConsole()
{ 
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

// Pauses the the console.
void pauseConsole()
{
    #ifdef _WIN32
    system("pause");
    #else
    system("read -n1 -r -p \"Press any key to continue...\" key");
    #endif
}
