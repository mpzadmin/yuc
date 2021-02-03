/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file any_file_copy.cpp
 * @brief A program which copies the content of one file into another.
 */

/** External Libraries **/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void clearConsole();

/**
 * Program's Entry Point
 */
int main(int argc, char* argv[])
{
    /** Local Variables **/
    string content;
    string pathFrom;
    string pathTo;
    ifstream fileFrom;
    ofstream fileTo;

    clearConsole();

    // Check args count
    if (argc > 3)
    {
        cout << "Too many provided arguments! Correct form: [program_name]  [file_to_read] [file_to_copy_to]" << endl;
        return 0;
    }
    if (argc < 3)
    {
        cout << "Not enough provided arguments! Correct form: [program_name]  [file_to_read] [file_to_copy_to]" << endl;
        return 0;
    }

    // Set filenames
    pathFrom = argv[1];
    pathTo = argv[2];

    fileFrom.open(pathFrom, ios::binary);
    fileTo.open(pathTo, ios::binary);

    if (!fileFrom.is_open() || !fileTo.is_open())
    {
        cout << "Error in opening the files!";
        return 0;
    }

    fileTo << fileFrom.rdbuf();

    if (fileFrom.fail() || fileTo.fail())
    {
        cout << "Error in copying the content!";
        return 0;
    }

    // Print the result
    cout << "Copying from \"" << pathFrom << "\" to \"" << pathTo << "\" was successful!";

    /** End of the program **/
    return 0;
}

/**
 * Clears the console (on any OS)
 */
void clearConsole()
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}
