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
string divisorsOf(const int &num);
void clearConsole();

// Program's Entry Point
int main(int argc, char* argv[])
{
    int number;
    string* args = new string[argc];

    clearConsole();

    for (size_t i = 0; i < argc; ++i)
    {
        args[i] = argv[i];
    }

    if (argc > 2)
    {
        cout << "ERROR: Too many provided arguments! [Enter one number as a parameter]" << endl;
        return 0;
    }
    if (argc < 2)
    {
        cout << "ERROR: Not enough provided arguments! [Enter a number as a parameter]" << endl;
        return 0;
    }

    try
    {
        number = stoi(args[1]);
    }
    catch (const exception &e)
    {
        cout << "ERROR: Invalid number!" << endl;
        return 0;
    }

    cout << divisorsOf(number) << endl;

    return 0;
}

// Returns the divisors of an int as a string
string divisorsOf(const int &num)
{
    string result;

    if (num > 0)
    {
        for (size_t i = num; i > 0; --i)
        {
            size_t remainder = num % i;

            if (remainder == 0)
            {
                result += to_string(i);

                if (i != 1)
                {
                    result += ", ";
                }
            }
        }
    }
    else if (num < 0)
    {
        for (int i = num; i < 0; ++i)
        {
            int remainder = num % i;

            if (remainder == 0)
            {
                result += to_string(i);

                if (i != -1)
                {
                    result += ", ";
                }
            }
        }
    }
    else
    {
        result = "Infinity";
    }

    return result;
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
