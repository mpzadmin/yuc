/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file console_utils.hpp
 * @brief A library containing useful functions related to the standard output stream (console) environment.
 */

/** External Libraries **/
#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

/** Namespaces **/
using namespace std;

namespace c //stands for console
{

// Contains color names to use with print and println functions.
enum Color
{
    DEFAULT, WHITE, BLACK, B_WHITE, B_BLACK,
    RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN,
    B_RED, B_GREEN, B_YELLOW, B_BLUE, B_MAGENTA, B_CYAN
};

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
 * Writes a colored string to the standard output stream.
 *
 * @param str The string which will be written to the console.
 * @param fgColor Console foreground color.
 * @param bgColor Console background color.
 */
void print(const string &str, const Color &fgColor, const Color &bgColor);

/**
 * Writes a colored string to the standard output stream.
 *
 * @param str The string which will be written to the console.
 * @param fgColor Console foreground color.
 */
void print(const string &str, const Color &fgColor);

/**
 * Goes to the next line.
 */
void println();

/**
 * Writes a string to the standard output stream, then goes to the next line.
 *
 * @param str The string which will be written to the console.
 */
void println(const string &str);

/**
 * Writes a colored string to the standard output stream, then goes to the next line.
 *
 * @param str The string which will be written to the console.
 * @param fgColor Console foreground color.
 * @param bgColor Console background color.
 */
void println(const string &str, const Color &fgColor, const Color &bgColor);

/**
 * Writes a colored string to the standard output stream, then goes to the next line.
 *
 * @param str The string which will be written to the console.
 * @param fgColor Console foreground color.
 */
void println(const string &str, const Color &fgColor);

/**
 * Writes a separator line to the standard output stream, then goes to the next line.
 *
 * @param separator The separator character which is used to draw a line with.
 * @param len Length of the line.
 */
void printlnSeparator(const char &separator, const size_t &len);

/**
 * Asks the user for a string, then goes to the next line.
 *
 * @param titleToPrint The text which will be shown to the user before getting the input.
 * @return User input
 */
string askString(const string &titleToPrint = defaultStringRequestTitle);

/**
 * Asks the user for an int, then goes to the next line.
 *
 * @param titleToPrint The text which will be shown to the user before getting the input.
 * @return User input
 */
int askInt(const string &titleToPrint = defaultIntRequestTitle);

/**
 * Asks the user for a float, then goes to the next line.
 *
 * @param titleToPrint The text which will be shown to the user before getting the input.
 * @return User input
 */
float askFloat(const string &titleToPrint = defaultIntRequestTitle);

/**
 * Clears the standard output stream (OS independent).
 */
void clear();

/**
 * Pauses the standard output stream by asking the user to press any key (OS independent).
 */
void pause();

// Prints a text.
void print(const string &str)
{
    cout << str;
}

// Prints a colored text.
void print(const string &str, const Color &fgColor, const Color &bgColor)
{
    string out = str;
    string fgCode, bgCode;
    string endFormatting = "\033[0m";

    switch (fgColor)
    {
        case WHITE:
            fgCode = "\x1B[37m";
            break;
        case B_WHITE:
            fgCode = "\x1B[97m";
            break;
        case B_BLACK:
            fgCode = "\x1B[90m";
            break;
        case BLACK:
            fgCode = "\x1B[30m";
            break;
        case RED:
            fgCode = "\x1B[31m";
            break;
        case GREEN:
            fgCode = "\x1B[32m";
            break;
        case YELLOW:
            fgCode = "\x1B[33m";
            break;
        case BLUE:
            fgCode = "\x1B[34m";
            break;
        case MAGENTA:
            fgCode = "\x1B[35m";
            break;
        case CYAN:
            fgCode = "\x1B[36m";
            break;
        case B_RED:
            fgCode = "\x1B[91m";
            break;
        case B_GREEN:
            fgCode = "\x1B[92m";
            break;
        case B_YELLOW:
            fgCode = "\x1B[93m";
            break;
        case B_BLUE:
            fgCode = "\x1B[94m";
            break;
        case B_MAGENTA:
            fgCode = "\x1B[95m";
            break;
        case B_CYAN:
            fgCode = "\x1B[96m";
            break;
        case DEFAULT:
            break;
    }
    if (fgColor != DEFAULT)
    {
        out.insert(0, fgCode);
        out.append(endFormatting);
    }

    switch (bgColor)
    {
        case WHITE:
            bgCode = "\x1B[47m";
            break;
        case B_WHITE:
            bgCode = "\x1B[107m";
            break;
        case B_BLACK:
            bgCode = "\x1B[100m";
            break;
        case BLACK:
            bgCode = "\x1B[40m";
            break;
        case RED:
            bgCode = "\x1B[41m";
            break;
        case GREEN:
            bgCode = "\x1B[42m";
            break;
        case YELLOW:
            bgCode = "\x1B[43m";
            break;
        case BLUE:
            bgCode = "\x1B[44m";
            break;
        case MAGENTA:
            bgCode = "\x1B[45m";
            break;
        case CYAN:
            bgCode = "\x1B[46m";
            break;
        case B_RED:
            bgCode = "\x1B[101m";
            break;
        case B_GREEN:
            bgCode = "\x1B[102m";
            break;
        case B_YELLOW:
            bgCode = "\x1B[103m";
            break;
        case B_BLUE:
            bgCode = "\x1B[104m";
            break;
        case B_MAGENTA:
            bgCode = "\x1B[105m";
            break;
        case B_CYAN:
            bgCode = "\x1B[106m";
            break;
        case DEFAULT:
            break;
    }
    if (bgColor != DEFAULT)
    {
        out.insert(0, bgCode);
        out.append(endFormatting);
    }

    print(out);
}

// Prints a colored text.
void print(const string &str, const Color &fgColor)
{
    print(str, fgColor, DEFAULT);
}

// Prints a new line.
void println()
{
    cout << endl;
}

// Prints a text and a new line.
void println(const string &str)
{
    print(str);
    println();
}

// Prints a colored text and a new line.
void println(const string &str, const Color &fgColor, const Color &bgColor)
{
    print(str, fgColor, bgColor);
    println();
}

// Prints a colored text and a new line.
void println(const string &str, const Color &fgColor)
{
    print(str, fgColor);
    println();
}

// Prints a separator line and a new line.
void printlnSeparator(const char &separator, const size_t &len)
{
    string separatorLine;

    for (size_t i = 0; i < len; ++i) {
        separatorLine += separator;
    }

    println(separatorLine);
}

// Asks the user for a string, then goes to a new line.
string askString(const string &titleToPrint)
{
    string data;

    print(titleToPrint);
    getline(cin, data);
    println();

    return data;
}

// Asks the user for an integer, then goes to a new line.
int askInt(const string &titleToPrint)
{
    int data;

    print(titleToPrint);
    cin >> data;
    println();
    cin.clear();
    cin.ignore();

    return data;
}

// Asks the user for a float, then goes to a new line.
float askFloat(const string &titleToPrint)
{
    float data;

    print(titleToPrint);
    cin >> data;
    println();
    cin.clear();
    cin.ignore();

    return data;
}

// Clears the console.
void clear()
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

// Pauses the the console.
void pause()
{
    #ifdef _WIN32
    system("pause");
    #else
    system("read -n1 -r -p \"Press any key to continue...\" key");
    #endif
}
}