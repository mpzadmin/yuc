/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

// External Libraries
#include <iostream>
#include <string>
// Windows Specific Libraries
#ifdef _WIN32
#include <windows.h>
#endif

// Namespaces
using namespace std;

// Constants
const string str1 = "I'm Ali Khaleqi Yekta...";
const string subStr1 = "Khaleqi";
const string str2 = "I'm learning C++!";
const string subStr2 = "C++";
const string str3 = "Thank you for teaching me C++.";
const string subStr3 = "C#";
const int colorWhite = 7;
const int colorBlue = 3;
const int colorPurple = 5;

// Function Declrations
int findString(string mainStr, string subStr);
void printSearchResult(string mainStr, string subStr, int index);
void clearConsole();

// Program's Entry Point
int main()
{
    int subStrIndex1 = findString(str1, subStr1);
    int subStrIndex2 = findString(str2, subStr2);
    int subStrIndex3 = findString(str3, subStr3);

    clearConsole();

    // Test
    printSearchResult(str1, subStr1, subStrIndex1);
    printSearchResult(str2, subStr2, subStrIndex2);
    printSearchResult(str3, subStr3, subStrIndex3);
}

// Return the index of first subStr in mainStr [-1 if nothing is found]
int findString(string mainStr, string subStr)
{
    int index = mainStr.find(subStr); 

    if (index != string::npos) 
        return index;

    return -1;
}

// Print the result in a specific format
void printSearchResult(string mainStr, string subStr, int index)
{
    // The coloring section could be a function and it would be better that way,
    // But it wasn't the main purpose of this homework.

    #ifdef _WIN32
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    #endif

    cout << "Position of ";

    #ifdef _WIN32
    SetConsoleTextAttribute(consoleHandle, colorBlue);  
    #endif

    cout << "\"" << subStr << "\"";

    #ifdef _WIN32
    SetConsoleTextAttribute(consoleHandle, colorWhite);  
    #endif

    cout << " in ";

    #ifdef _WIN32
    SetConsoleTextAttribute(consoleHandle, colorBlue);  
    #endif

    cout << "\"" << mainStr << "\"";

    #ifdef _WIN32
    SetConsoleTextAttribute(consoleHandle, colorWhite);  
    #endif

    cout << ": ";

    #ifdef _WIN32
    SetConsoleTextAttribute(consoleHandle, colorPurple);  
    #endif

    cout << index << endl;

    #ifdef _WIN32
    SetConsoleTextAttribute(consoleHandle, colorWhite);  
    #endif
}

// Clear the console (on any OS)
void clearConsole()
{ 
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}
