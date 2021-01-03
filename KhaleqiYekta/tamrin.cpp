/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file tamrin.cpp
 * @brief A program which gets a group of names plus one name from the user and tell whether the name exists in names or not.
 */

/** External Libraries **/
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include "console.hpp"

/** Namespaces **/
using namespace std;

/** Function Declarations **/
bool search(const list<string> names, const string name);

// Program's Entry Point
int main()
{
    /** Initialization Of Local Variables **/
    list<string> names;
    string name;
    size_t namesCount;

    clearConsole();

    namesCount = askForInt("Enter the count of names: ");

    for (size_t i = 0; i < namesCount; ++i)
    {
        name = askForString("Enter name " + to_string(i + 1) + ": ");
        names.push_back(name);
    }

    name = askForString("Enter a name to search in names: ");

    if (search(names, name))
    {
        printLine(name + " was found!");
    }
    else
    {
        printLine(name + " was not found!");
    }

    /** End of the program **/
    pauseConsole();
    return 0;
}

bool search(const list<string> names, const string name)
{
    for (string n : names)
    {
        if (n == name)
        {
            return true;
        }
    }

    return false;
}
