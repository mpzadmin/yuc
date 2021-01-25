/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file string_repeat_counter.cpp
 * @brief A program which gets some names, then shows the repeat count of repeated names.
 */
 
/** External Libraries **/
#include <string>
#include <vector>
#include <algorithm>
#include "../../../Desktop/University/Programming Class/c++/samyad/console.hpp"

/** Namespaces **/
using namespace std;

/** Constants **/
const char lineChar = '=';
const size_t lineSize = 40;

/** Function Declarations **/
int search(const vector<string>& names, const string& name);

// Program's Entry Point
int main()
{
    /** Local Variables **/
    vector<string> names;
    vector<size_t> counts;
    bool duplicatedNameExists = false;

    clearConsole();

    for (size_t i = 1; true; ++i)
    {
        string input;
        int nameIndex;

        input = askForString("Enter name " + to_string(i) + " [Empty if done]: ");

        // Break the loop if input is empty
        if (input.empty())
        {
            break;
        }

        nameIndex = search(names,input);

        // New name
        if (nameIndex == -1)
        {
            names.(input);
            counts.push_back(1);
        }
        // Existing name
        else
        {
            duplicatedNameExists = true;
            counts[nameIndex] += 1;
        }
    }

    // Print the results
    printSeparatorLine(lineChar, lineSize);
    printLine("Result: ");

    if (duplicatedNameExists)
    {
        for (size_t i = 0; i < names.size(); ++i)
        {
            // Print the repeat count of repeated names
            if (counts[i] > 1)
            {
                printLine("Name: " + names[i] + "\t\tCount: " + to_string(counts[i]));
            }
        }
    }
    else
    {
        printLine("\tThere are no duplicated names!");
    }

    printSeparatorLine(lineChar, lineSize);

    /** End of the program **/
    pauseConsole();
    return 0;
}

int search(const vector<string>& names, const string& name)
{
    for (size_t i = 0; i < names.size() ; ++i)
    {
        if (names[i] == name)
        {
            return i;
        }
    }

    return -1;
}
