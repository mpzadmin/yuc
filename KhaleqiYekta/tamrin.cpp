/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file tamrin.cpp
 * @brief A program which gets a filename and a word from user
 * and shows the repeat count of that word in the file.
 * [Each word is in one line]
 */

/** External Libraries **/
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include "console.hpp"

/** Namespaces **/
using namespace std;

/** Other Variables **/
fstream textFile;
string fileName;

/** Function Declarations **/
size_t getCount(const string& wantedWord);

// Program's Entry Point
int main() {
    /** Local Variables **/
    string word;
    size_t wordCount;

    clearConsole();

    fileName = askForString("Enter the filename: ");
    if (fileName.empty())
    {
        printLine("Filename cannot be empty!");
        return 0;
    }

    word = askForString("Enter the word you want to know the repeat count of: ");
    if (word.empty())
    {
        printLine("This word cannot be empty!");
        return 0;
    }

    wordCount = getCount(word);

    printSeparatorLine('=',40);

    if (wordCount == 0)
    {
        printLine("Result: The word \"" + word + "\" does not exist in file: " + fileName);
    }
    else if (wordCount == 1)
    {
        printLine("Result: The word \"" + word + "\" is repeated 1 time in file: " + fileName);
    }
    else
    {
        printLine("Result: The word \"" + word + "\" is repeated " + to_string(wordCount) + " times in file: " + fileName);
    }

    printSeparatorLine('=',40);

    /** End of the program **/
    pauseConsole();
    return 0;
}

size_t getCount(const string& wantedWord)
{
    string wordInLine;
    size_t wordCount = 0;

    textFile.open(fileName, ios::in);
    if (!textFile.is_open())
    {
        printLine("Error in opening the file!");
        return 0;
    }

    while (!textFile.eof())
    {
        getline(textFile, wordInLine);
        if (wordInLine == wantedWord)
        {
            wordCount++;
        }
    }

    textFile.close();

    return wordCount;
}