/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file check.hpp
 * @brief A library containing all of the project needs.
 */

/** External Libraries **/
#include <iostream>
#include <string>
#include <vector>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

struct Check
{
    int number{};
    Date date{};
    string personName;
    long amount{};
};

typedef list<Check> CheckList;

/** Constants **/
const string errInvalidNum = "Invalid number!";
const string errInvalidName = "Invalid name!";
const string errNoChecks = "You don't have any checks!";
const string errNoChecksInDateRange = "No checks exist in this date!";
const string errChecksOutOfBounds = "Check index out of bounds!";
const string errCheckAlreadyAdded = "A check with this number is already added!";
const string errCheckNotFound = "Check not found!";
const string errInvalidInput = "Invalid input!";
const string errParseFile = "Error in parsing the data file!";
const string errSaveFile = "Changes couldn't be saved!";

const string infCheckAdded = "Check added!";
const string infCheckUpdated = "Check updated!";
const string infCheckDeleted = "Check deleted!";

const string strFileName = "check_data.txt";
const string strStartDate = "You need to specify the start of the date range...";
const string strEndDate = "You need to specify the end of the date range...";
const string strEnterCheckNum = "Enter the check number: ";
const string strEnterCheckAmount = "Enter the check amount: ";
const string strEnterCheckYear = "Enter the check year: ";
const string strEnterCheckMonth = "Enter the check month: ";
const string strEnterCheckDay = "Enter the check day: ";
const string strEnterPersonName = "Enter the person name: ";
const string strSelectOption = "\nPlease select an option: ";

const string optEditCheck = "Edit check";
const string optDeleteCheck = "I'm sure, Delete the check!";
const string optGoBack = "Go back";

const string nl = "\n";

/** Function Declarations **/

/**
 * Checks if a check exists in a list of checks.
 *
 * @param checks The list of checks.
 * @param number The number of the check which is going to be checked.
 *
 * @return Whether a check exists in a list of checks.
 */
bool checkExists(CheckList &checks, int number);

/**
 * Compares two checks by date.
 *
 * @param a The first check.
 * @param b The second check.
 *
 * @return Is a newer than b.
 */
bool compareData(const Check &a, const Check &b);

/**
 * Sorts the list of checks by date.
 *
 * @param checks The list of checks to sort.
 */
void sortList(CheckList &checks);

/**
 * Deletes a check by check number.
 *
 * @param checks The list of checks.
 * @param number The number of the check which is going to be deleted.
 */
void deleteCheckByNum(CheckList &checks, int number);

/**
 * Gets a check by check number.
 *
 * @param checks The list of checks.
 * @param number The number of the check which is going to be returned.
 *
 * @return A check which numbers' is the entered number.
 */
Check &getCheckByNum(CheckList &checks, int number);

/**
 * Gets a check by index in list.
 *
 * @param checks The list of checks.
 * @param index The index of the check which is going to be returned.
 *
 * @return The check in checks[index].
 */
Check &getCheckByIndex(CheckList &checks, int index);

/**
 * Gets checks in a date range.
 *
 * @param checks The list of checks.
 * @param start Start of the range.
 * @param end End of the range.
 *
 * @return List of checks which are in the selected range.
 */
CheckList getChecksByDateRange(CheckList &checks, Date start, Date end);

/**
 * Gets a check by name.
 *
 * @param checks The list of checks.
 * @param name A name which the check name is going to contain.
 *
 * @return A check which contains string &name.
 */
Check &getCheckByName(CheckList &checks, string &name);


// Checks if a check exists in a list of checks.
bool checkExists(CheckList &checks, int number)
{
    for (Check &check : checks)
    {
        if (check.number == number)
        {
            return true;
        }
    }

    return false;
}

// Compares two checks by date.
bool compareData(const Check &a, const Check &b)
{
    CheckList output;

    int aDate = (a.date.year * 10000) + (a.date.month * 100) + a.date.day;
    int bDate = (b.date.year * 10000) + (b.date.month * 100) + b.date.day;

    if (aDate > bDate)
    {
        return true;
    }

    return false;
}

// Sorts the list of checks by date.
void sortList(CheckList &checks)
{
    for(int i = 0; i < checks.size(); ++i)
    {
        for (int j = i+1; j < checks.size(); ++j)
        {
            Check c1 = getCheckByIndex(checks, i);
            Check c2 = getCheckByIndex(checks, j);

            if (compareData(c1, c2))
            {
                swap(*next(checks.begin(), i), *next(checks.begin(), j));
            }
        }
    }
}

// Deletes a check by number.
void deleteCheckByNum(CheckList &checks, int number)
{
    auto i = checks.begin();

    while (i != checks.end())
    {
        if ((*i).number == number)
        {
            checks.erase(i);
            return;
        }
        else
        {
            i++;
        }
    }

    throw_with_nested(errCheckNotFound);
}

// Gets checks in a date range.
CheckList getChecksByDateRange(CheckList &checks, Date start, Date end)
{
    CheckList output;
    int date;
    int s = (start.year * 10000) + (start.month * 100) + start.day;
    int e = (end.year * 10000) + (end.month * 100) + end.day;

    for (Check &check : checks)
    {
        date = (check.date.year * 10000) + (check.date.month * 100) + check.date.day;

        if (date >= s && date <= e)
        {
            output.push_back(check);
        }
    }

    return output;
}

// Gets a check by name.
Check &getCheckByName(CheckList &checks, string &name)
{
    for (Check &check : checks)
    {
        if (check.personName.find(name) != string::npos)
        {
            return check;
        }
    }

    throw_with_nested(errChecksOutOfBounds);
}

// Get a check by number.
Check &getCheckByNum(CheckList &checks, int number)
{
    for (Check &check : checks)
    {
        if (check.number == number)
        {
            return check;
        }
    }

    throw_with_nested(errChecksOutOfBounds);
}

// Get a check by index in the list.
Check &getCheckByIndex(CheckList &checks, int index)
{
    if (checks.size() > index)
    {
        return *next(checks.begin(), index);
    }
    else
    {
        throw_with_nested(errChecksOutOfBounds);
    }
}

// All console-related functions are here.
namespace console
{

// Contains color names to use with print and println functions.
enum Color
{
    DEFAULT, WHITE, BLACK, B_WHITE, B_BLACK,
    RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN,
    B_RED, B_GREEN, B_YELLOW, B_BLUE, B_MAGENTA, B_CYAN
};

/** Function Declarations **/

/**
 * Asks user to add a check.
 *
 * @return A check with user inputs.
 */
Check askCheck();

/**
 * Asks user to add a date.
 *
 * @return A date with user inputs.
 */
Date askDate();

/**
 * Prints a list of checks.
 *
 * @param checks The list which is going to be printed.
 */
void printChecks(CheckList &checks);

/**
 * Prints a check.
 *
 * @param checks The check which is going to be printed.
 */
void printCheck(const Check &check);

/**
 * Prints the main page in the standard output stream.
 */
void printMainPage();

/**
 * Writes the menu items to the standard output stream with an index assigned to each one (Starting at 1).
 *
 * @param items The items of the menu which are in the correct order.
 */
void printMenuItems(const vector<string> &items);

/**
 * Writes an info to the standard output stream.
 *
 * @param str The info which will be written to the console.
 */
void printInfo(const string &str);

/**
 * Writes an error to the standard output stream.
 *
 * @param str The error which will be written to the console.
 */
void printError(const string &str);

/**
 * Writes a string to the standard output stream.
 *
 * @param str The string which will be written to the console.
 */
void print(const string &str);

/**
 * Writes a colored string to the standard output stream.
 *
 * @param str The string which will be written to the console.
 * @param fgColor Console foreground color.
 * @param bgColor Console background color.
 */
void print(const string &str, const Color &fgColor, const Color &bgColor);

/**
 * Writes a colored string to the standard output stream.
 *
 * @param str The string which will be written to the console.
 * @param fgColor Console foreground color.
 */
void print(const string &str, const Color &fgColor);

/**
 * Goes to the next line.
 */
void println();

/**
 * Writes a colored string to the standard output stream, then goes to the next line.
 *
 * @param str The string which will be written to the console.
 * @param fgColor Console foreground color.
 */
void println(const string &str, const Color &fgColor);

/**
 * Asks the user for a string, then goes to the next line.
 *
 * @return User input
 */
string askString(const string &titleToPrint);

/**
 * Asks the user for an integer, then goes to the next line.
 *
 * @return User input
 */
int askInt(const string &titleToPrint);

/**
 * Asks the user for a long, then goes to the next line.
 *
 * @return User input
 */
long askLong(const string &titleToPrint);

/**
 * Clears the standard output stream (OS independent).
 */
void clear();

/**
 * Pauses the standard output stream by asking the user to press any key (OS independent).
 */
void pause();

// Asks user to add a check.
Check askCheck()
{
    Check check;

    clear();

    // Get number
    do
    {
        check.number = askInt(strEnterCheckNum);
        if (check.number <= 0)
        {
            clear();
            printError(errInvalidNum);
        }
    }
    while (check.number <= 0);

    clear();

    // Get date
    check.date = askDate();

    clear();

    // Get person name
    do
    {
        check.personName = askString(strEnterPersonName);
        if (check.personName.empty())
        {
            clear();
            printError(errInvalidName);
        }
    }
    while (check.personName.empty());

    clear();

    // Get amount
    do
    {
        check.amount = askLong(strEnterCheckAmount);
        if (check.amount <= 0)
        {
            clear();
            printError(errInvalidNum);
        }
    }
    while (check.amount <= 0);

    return check;
}

// Asks user to add a date.
Date askDate()
{
    Date date{};

    // Get Year
    do
    {
        date.year = askInt(strEnterCheckYear);
        if (date.year <= 0)
        {
            clear();
            printError(errInvalidNum);
        }
    }
    while (date.year <= 0);

    clear();

    // Get Month
    do
    {
        date.month = askInt(strEnterCheckMonth);
        if (date.month < 1 || date.month > 12)
        {
            clear();
            printError(errInvalidNum);
        }
    }
    while (date.month < 1 || date.month > 12);

    clear();

    // Get Day
    do
    {
        date.day = askInt(strEnterCheckDay);
        if (date.day < 1 || date.day > 31)
        {
            clear();
            printError(errInvalidNum);
        }
    }
    while (date.day < 1 || date.day > 31);

    clear();

    return date;
}

// Prints a list of checks.
void printChecks(CheckList &checks)
{
    for (int i = 0; i < checks.size(); ++i)
    {
        printCheck(getCheckByIndex(checks, i));
    }
}

// Prints a check.
void printCheck(const Check &check)
{
    string checkNum = to_string(check.number);
    string date = to_string(check.date.year) + "." + to_string(check.date.month) + "." + to_string(check.date.day);
    string name = check.personName;
    string amount = to_string(check.amount);

    println("* Check details: ", YELLOW);
    print("\tNumber:\t\t", WHITE);
    println(checkNum, B_MAGENTA);
    print("\tDate:\t\t", B_WHITE);
    println(date, B_MAGENTA);
    print("\tPerson name:\t", WHITE);
    println(name, B_MAGENTA);
    print("\tAmount:\t\t", B_WHITE);
    println(amount, B_MAGENTA);
    println();
}

// Prints the main page.
void printMainPage()
{
    vector<string> menuItems;

    // In here, emplace_back is equivalent to push_back.
    menuItems.emplace_back("New check");
    menuItems.emplace_back(optEditCheck);
    menuItems.emplace_back("Delete check");
    menuItems.emplace_back("Search check by number");
    menuItems.emplace_back("Search check by name");
    menuItems.emplace_back("Search check by date");
    menuItems.emplace_back("List All checks");
    menuItems.emplace_back("Exit");

    clear();
    console::println("[Main Menu]\n", B_MAGENTA);
    console::printMenuItems(menuItems);
}

// Prints the menu items
void printMenuItems(const vector<string> &items)
{
    for (size_t i = 0; i < items.size(); ++i)
    {
        string itemIndexStr = to_string(i + 1) + ". ";

        // Making the indexes colored and pretty!
        Color c;
        if (i % 2 == 0)
        {
            c = CYAN;
        }
        else
        {
            c = B_CYAN;
        }

        print(itemIndexStr, c);
        println(items[i], B_WHITE);
    }
}

// Prints an info.
void printInfo(const string &str)
{
    print("INFO:", console::B_WHITE, console::GREEN);
    println(" " + str, console::B_GREEN);
}

// Prints an error.
void printError(const string &str)
{
    print("ERROR:", console::B_WHITE, console::RED);
    println(" " + str, console::B_RED);
}

// Prints a text.
void print(const string &str)
{
    cout << str;
}

// Prints a colored text.
void print(const string &str, const Color &fgColor, const Color &bgColor)
{
    string out = str;
    string fgCode, bgCode;
    string endFormatting = "\033[0m";

    switch (fgColor)
    {
        case WHITE:
            fgCode = "\x1B[37m";
            break;
        case B_WHITE:
            fgCode = "\x1B[97m";
            break;
        case B_BLACK:
            fgCode = "\x1B[90m";
            break;
        case BLACK:
            fgCode = "\x1B[30m";
            break;
        case RED:
            fgCode = "\x1B[31m";
            break;
        case GREEN:
            fgCode = "\x1B[32m";
            break;
        case YELLOW:
            fgCode = "\x1B[33m";
            break;
        case BLUE:
            fgCode = "\x1B[34m";
            break;
        case MAGENTA:
            fgCode = "\x1B[35m";
            break;
        case CYAN:
            fgCode = "\x1B[36m";
            break;
        case B_RED:
            fgCode = "\x1B[91m";
            break;
        case B_GREEN:
            fgCode = "\x1B[92m";
            break;
        case B_YELLOW:
            fgCode = "\x1B[93m";
            break;
        case B_BLUE:
            fgCode = "\x1B[94m";
            break;
        case B_MAGENTA:
            fgCode = "\x1B[95m";
            break;
        case B_CYAN:
            fgCode = "\x1B[96m";
            break;
        case DEFAULT:
            break;
    }
    if (fgColor != DEFAULT)
    {
        out.insert(0, fgCode);
        out.append(endFormatting);
    }

    switch (bgColor)
    {
        case WHITE:
            bgCode = "\x1B[47m";
            break;
        case B_WHITE:
            bgCode = "\x1B[107m";
            break;
        case B_BLACK:
            bgCode = "\x1B[100m";
            break;
        case BLACK:
            bgCode = "\x1B[40m";
            break;
        case RED:
            bgCode = "\x1B[41m";
            break;
        case GREEN:
            bgCode = "\x1B[42m";
            break;
        case YELLOW:
            bgCode = "\x1B[43m";
            break;
        case BLUE:
            bgCode = "\x1B[44m";
            break;
        case MAGENTA:
            bgCode = "\x1B[45m";
            break;
        case CYAN:
            bgCode = "\x1B[46m";
            break;
        case B_RED:
            bgCode = "\x1B[101m";
            break;
        case B_GREEN:
            bgCode = "\x1B[102m";
            break;
        case B_YELLOW:
            bgCode = "\x1B[103m";
            break;
        case B_BLUE:
            bgCode = "\x1B[104m";
            break;
        case B_MAGENTA:
            bgCode = "\x1B[105m";
            break;
        case B_CYAN:
            bgCode = "\x1B[106m";
            break;
        case DEFAULT:
            break;
    }
    if (bgColor != DEFAULT)
    {
        out.insert(0, bgCode);
        out.append(endFormatting);
    }

    print(out);
}

// Prints a colored text.
void print(const string &str, const Color &fgColor)
{
    print(str, fgColor, DEFAULT);
}

// Prints a new line.
void println()
{
    cout << endl;
}

// Prints a colored text and a new line.
void println(const string &str, const Color &fgColor)
{
    print(str, fgColor);
    println();
}

// Asks the user for a string, then goes to a new line.
string askString(const string &titleToPrint)
{
    string data;

    print(titleToPrint, B_YELLOW);
    getline(cin, data);
    println();

    return data;
}

// Asks the user for an integer, then goes to a new line.
int askInt(const string &titleToPrint)
{
    try
    {
        int data;

        print(titleToPrint, B_YELLOW);
        cin >> data;
        println();
        cin.clear();
        cin.ignore();

        return data;
    }
    catch (exception &e)
    {
        return -999999;
    }
}

// Asks the user for an integer, then goes to a new line.
long askLong(const string &titleToPrint)
{
    try
    {
        long data;

        print(titleToPrint, B_YELLOW);
        cin >> data;
        println();
        cin.clear();
        cin.ignore();

        return data;
    }
    catch (exception &e)
    {
        return -999999999;
    }
}

// Clears the console.
void clear()
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

// Pauses the the console.
void pause()
{
    #ifdef _WIN32
    system("pause");
    #else
    system("read -n1 -r -p \"Press any key to continue...\" key");
    #endif
}
}
