/*
 *  @brief Console Utilities Library
 * 
 *  @author YektaDev [Ali Khaleqi Yekta]
 *  Website: Yekta.Dev
 *  Email: Me@Yekta.Dev
 */

/** External Libraries **/
#include <iostream>
#include <string>

/** Namespaces **/
using namespace std;

/** Constants **/
const string defaultStringRequestTitle = "Please enter a text: ";
const string defaultIntRequestTitle = "Please enter a number: ";

/** Function Declrations **/
void print(string str);
void newLine();
void printLine(string str);
string askForString(string titleToPrint = defaultStringRequestTitle);
int askForInt(string titleToPrint = defaultIntRequestTitle);
void clearConsole();

// Prints a text
void print(string str)
{
    cout << str;
}

// Ends the line
void newLine()
{
    cout << endl;
}

// Prints a text and end the line
void printLine(string str)
{
    print(str);
    newLine();
}

// Returns a string which is requested from user, then goes to a new line after the procces is done.
string askForString(string titleToPrint)
{
    string data;

    print(titleToPrint);
    getline(cin, data);
    newLine();

    return data;
}

// Returns an integer which is requested from user, then goes to a new line after the procces is done.
int askForInt(string titleToPrint)
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
