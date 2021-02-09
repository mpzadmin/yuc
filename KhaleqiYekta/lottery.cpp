/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file lottery.cpp
 * @brief A program which picks random serial numbers from those that user submitted.
 */

/** External Libraries **/
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

fstream file;
string msg;
int option;

/** Function Declarations **/

/**
 * Asks the user for an int, then goes to the next line.
 *
 * @param titleToPrint The text which will be shown to the user before getting the input.
 * @return User input
 */
int askForInt(const string &titleToPrint);

/**
 * Clears the standard output stream (OS independent).
 */
void clearConsole();

/**
 * Pauses the standard output stream by asking the user to press any key (OS independent).
 */
void pauseConsole();

/**
 * Prints the main menu and reads the option.
 *
 * @param message The message to print at the top of the menu.
 */
void restartMenu(const string& message = "");

/**
 * Goes to the part which is related to getting the lottery serials from the user.
 */
void getNums();

/**
 * Gets the draw count and draws some serial numbers randomly.
 */
void drawNums();

/**
 * Writes a number to the text file.
 *
 * @return Whether the operation was successful or not.
 */
bool writeNumberToFile(int number);

/**
 * Reads serials count
 *
 * @return Serials count
 */
int countNums();

/**
 * Program's Entry Point
 */
int main()
{
    // Create the file if doesn't exists
    file.open("lottery.txt", ios::out | ios_base::app);
    file.close();

    while (true)
    {
        restartMenu(msg);
        msg = "";

        switch (option)
        {
            case 1:
                getNums();
                break;

            case 2:
                drawNums();
                break;

            case 3:
                return 0;

            default:
                msg = "\x1B[91mInvalid Input!\033[0m";
        }
    }
}

void restartMenu(const string &message)
{
    clearConsole();

    cout << message << endl;
    cout << "\x1B[93m1.\033[0m Enter the lottery serial numbers" << endl;
    cout << "\x1B[93m2.\033[0m Draw some serial numbers randomly" << endl;
    cout << "\x1B[93m3.\033[0m Exit" << endl << endl;

    option = askForInt("Select an option: ");
}

void getNums()
{
    clearConsole();

    int num = askForInt("Enter a serial: ");
    while (num != 0)
    {
        if (!writeNumberToFile(num))
        {
            cout << "Serial wasn't able to be saved!";
            return;
        }

        num = askForInt("Enter a serial (0 if finished): ");
    }
}

void drawNums()
{
    int count;
    int linesCount = countNums();

    if (linesCount == 0)
    {
        msg = "\x1B[91mYou haven't entered any serials yet!\033[0m";
        return;
    }

    clearConsole();
    count = askForInt("Enter the count of serials you want to draw: ");
    clearConsole();

    if (count > linesCount)
    {
        msg = "\x1B[91mCount can not be greater than the serial numbers!\033[0m";
        return;
    }

    srand((unsigned) time(nullptr));

    for (size_t i = 0; i < count; ++i)
    {
        size_t lineIndex = rand() % linesCount;
        string line;

        file.open("lottery.txt", ios::in);

        for (size_t j = 0; ; ++j)
        {
            getline(file, line);

            if (j == lineIndex)
            {
                cout << line << endl;
                break;
            }
        }

        file.close();
    }

    pauseConsole();
}

bool writeNumberToFile(int number)
{
    file.open("lottery.txt", ios::out | ios_base::app);

    file << number << endl;
    if (file.fail())
    {
        return false;
    }

    file.close();

    return true;
}

int countNums()
{
    int c;

    file.open("lottery.txt", ios::in);
    c = count(istreambuf_iterator<char>(file), istreambuf_iterator<char>(), '\n');
    file.close();

    return c;
}

int askForInt(const string &titleToPrint)
{
    int data;

    cout << titleToPrint;
    cin >> data;
    cout << endl;
    cin.clear();
    cin.ignore();

    return data;
}

void clearConsole()
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void pauseConsole()
{
    #ifdef _WIN32
    system("pause");
    #else
    system("read -n1 -r -p \"Press any key to continue...\" key");
    #endif
}
