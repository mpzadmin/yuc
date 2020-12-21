/*
 *  @brief TODO: [PROGRAM NAME]
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
string askForString(string titleToPrint = defaultStringRequestTitle);
int askForInt(string titleToPrint = defaultIntRequestTitle);
void clearConsole();

// Program's Entry Point
int main()
{
    /* TODO: VARIABLES GO HERE */

    clearConsole();

    /* TODO: CODE GOES HERE */

    return 0;
}

/* TODO: PROGRAM FUNCTIONS GO HERE */

// Returns a string which is requested from user, then goes to a new line after the procces is done.
string askForString(string titleToPrint)
{
    string data;

    cout << titleToPrint;
    getline(cin, data);
    cout << endl;

    return data;
}

// Returns an integer which is requested from user, then goes to a new line after the procces is done.
int askForInt(string titleToPrint)
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
