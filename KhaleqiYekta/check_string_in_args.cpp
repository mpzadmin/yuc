/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/** External Libraries **/
#include <iostream>
#include <string>

/** Namespaces **/
using namespace std;

/** Function Declarations **/
void clearConsole();

// Program's Entry Point
int main(int argc, char* argv[])
{
    string* args = new string[argc];
    for (size_t i = 0; i < argc; ++i)
    {
        args[i] = argv[i];
    }

    clearConsole();

    if (argc > 3)
    {
        cout << "ERROR: Too many provided arguments! [Enter 2 parameters]" << endl;
        return 0;
    }
    if (argc < 3)
    {
        cout << "ERROR: Not enough provided arguments! [Enter 2 parameters]" << endl;
        return 0;
    }

    if(args[1] == args[2])
    {
        cout << "SAME" << endl;
    }
    else
    {
        cout << "NOT SAME" << endl;
    }

    return 0;
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
