/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file textfile_copy.cpp
 * @brief A program which copies the content of one file into another.
 */

/** External Libraries **/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

/** Namespaces **/
using namespace std;

/** Other Variables **/
fstream fileFrom;
fstream fileTo;
string pathFrom;
string pathTo;

/** Function Declarations **/
void closeFiles();
string readFromFirstFile();
bool openFiles();
void clearConsole();

// Program's Entry Point
int main(int argc, char* argv[])
{
    /** Local Variables **/
    string content;

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

    // Open the files
    if (!openFiles())
    {
        cout << "Error in opening the files!";
        return 0;
    }

    // Read from fileFrom
    content = readFromFirstFile();
    if (fileFrom.fail())
    {
        cout << "Error in processing the file!";
        return 0;
    }

    // Write to fileTo
    fileTo << content;
    if (fileTo.fail())
    {
        cout << "Error in copying the content!";
        return 0;
    }

    // Close the files
    closeFiles();

    // Print the result
    cout << "Copying from \"" << pathFrom << "\" to \"" << pathTo << "\" was successful!";

    /** End of the program **/
    return 0;
}

// Close the files
void closeFiles()
{
    fileTo.close();
    fileFrom.close();
}

// Read from fileFrom
string readFromFirstFile()
{
    ostringstream strStream;
    strStream << fileFrom.rdbuf();

    return strStream.str();
}

// Open the files
bool openFiles()
{
    fileFrom.open(pathFrom, ios::in);
    fileTo.open(pathTo, ios::out);

    return fileFrom.is_open() && fileTo.is_open();
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
