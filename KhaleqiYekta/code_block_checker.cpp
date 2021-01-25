/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file code_block_checker.cpp
 * @brief A program which parses a code file which is addressed
 * through program's arguments and checks the code blocks.
 */

/** External Libraries **/
#include <iostream>
#include <string>
#include <fstream>
#include "console.hpp"

/** Namespaces **/
using namespace std;

/** Other Variables **/
string fileName;
fstream textFile;

/** Function Declarations **/
bool openFile();

// Program's Entry Point
int main(int argc, char* argv[])
{
    fileName = argv[1];
    char ch;
    int blocksTotal = 0;
    int blocksTemp = 0;
    int blocksLastTemp = 0;
    int lines = 1;
    int firstUnclosedBlockLine = 0;

    clearConsole();

    // Check args count
    if (argc > 2)
    {
        printLine("Too many provided arguments! [Enter only one parameter]");
        pauseConsole();
        return 0;
    }
    if (argc < 2)
    {
        printLine("Not enough provided arguments! [Enter the file address]");
        pauseConsole();
        return 0;
    }

    // Open the file
    if (!openFile())
    {
        printLine("Error in opening the file!");
        pauseConsole();
        return 0;
    }

    // Process the file
    while (textFile >> noskipws >> ch)
    {
        if (textFile.fail())
        {
            printLine("Error while processing the file!");
            pauseConsole();
            return 0;
        }

        if (ch == '\n')
        {
            lines++;
        }
        else if (ch == '{')
        {
            blocksTemp++;
            blocksTotal++;
        }
        else if (ch == '}')
        {
            blocksTemp--;
        }

        if (blocksTemp < 0)
        {
            printLine("An invalid block found in line: " + to_string(lines));
            pauseConsole();
            return 0;
        }
        else if (blocksTemp == 1 && blocksLastTemp == 0) // Means that temp was 0 and now is 1
        {
            firstUnclosedBlockLine = lines;
        }
        else if (blocksTemp == 0)
        {
            firstUnclosedBlockLine = 0;
        }

        blocksLastTemp = blocksTemp;
    }

    if (blocksTemp == 0) // Everything is OK
    {
        printLine("The total number of blocks is: " + to_string(blocksTotal));
    }
    else // => (blocksTemp > 0)
    {
        printLine("An invalid block found in line: " + to_string(firstUnclosedBlockLine));
    }

    /** End of the program **/
    pauseConsole();
    return 0;
}

// Open the file
bool openFile()
{
    textFile.open(fileName, ios::in);
    return textFile.is_open();
}
