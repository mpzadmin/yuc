/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file delay.cpp
 * @brief A program which creates a delay in console.
 */

/** External Libraries **/
#include <iostream>
#include <string>

/** Namespaces **/
using namespace std;

/** Constants **/
const int delayValue = 50;
const string textToPrint = "Hello C++ Class!";

/** Function Declarations **/
void clearConsole();
void delay(int delay = 10);

// Program's Entry Point
int main()
{
    clearConsole();

    for (int i = 0; i < textToPrint.length(); i++)
    {
        delay(delayValue);

        cout << textToPrint[i];
    }

    return 0;
}

// Blocks the thread for some time
void delay(int delay)
{ 
    for (int i = 0; i < 1000000; i++)
    {
        for (int j = 0; j < delay; j++);
    }
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
