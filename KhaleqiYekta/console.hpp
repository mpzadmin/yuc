/*
 * Copyright © 2020 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 * Creation Date: 2020-12-18
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
void print(const string &str);
void newLine();
void printLine(const string &str);
string askForString(const string &titleToPrint = defaultStringRequestTitle);
int askForInt(const string &titleToPrint = defaultIntRequestTitle);
void clearConsole();

// Prints a text
void print(const string &str)
{
    cout << str;
}

// Ends the line
void newLine()
{
    cout << endl;
}

// Prints a text and end the line
void printLine(const string &str)
{
    print(str);
    newLine();
}

// Returns a string which is requested from user, then goes to a new line after the process is done.
string askForString(const string &titleToPrint)
{
    string data;

    print(titleToPrint);
    getline(cin, data);
    newLine();

    return data;
}

// Returns an integer which is requested from user, then goes to a new line after the process is done.
int askForInt(const string &titleToPrint)
{
    int data;

    print(titleToPrint);
    cin >> data;
    newLine();

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
