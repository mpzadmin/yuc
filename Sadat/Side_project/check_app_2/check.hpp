/**
 * copyright (c) 2021-2022
 * Pouya Sadat
 * pouya.s2781@gmail.com
 * 
 * @file "check.hpp"
 * a library full of functions and structures for checks
 */

#include <iostream>
#include <list>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

// variable and structure declaration
typedef unsigned long long int large_t;
typedef unsigned short int small_t;
const string fileName = "data.dat";
const int maxAmountLength = 18;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
enum BackgroundColor {Black = 0, Blue = 1, Green = 2, Red = 4, Perpule = 5, Yellow = 6, Gray = 8 , Def = 7};
struct Date
{
    small_t day;
    small_t month;
    small_t year;
};
struct Check
{
    string number;
    large_t amount;
    string personName;
    Date date;
};
Check failSearch = {"", 0, "", {0, 0, 0}};

// function declaration
bool isSameCheck(Check firstCheck, Check secondCheck);
bool isNumber(string number);
int isMatching(string personName, string name);
large_t stringToInt(string number);
list<Check> searchByPersonName(list<Check> checks, string name);
list<Check> searchByDate(list<Check> checks, Date startDate, Date endDate);
Check searchByNumber(list<Check> checks, string number);
Check getCheckData(list<Check> checks);
void showChecks(list<Check> checks, string highlight, BackgroundColor color);
void editByNumber(list<Check>& checks, string checkNumber);
void deleteByNumber(list<Check>& checks, string number);
void getDateInterval(Date& startDate, Date& endDate);
void getAmountInterval(large_t& sAmount, large_t& eAmount);
void getOption(int& option, int startNumber, int endNumber);
void getNumber(string& number);
void readChecks(list<Check>& checks);
void writeChecks(list<Check> checks);
void sortByDate(list<Check>& checks);
void showChecks(list<Check> checks);
void showChecks(Check check);
void showYesNo();
void showOptions();
void showEditOptions();
void showDeleteOptions();

/**
 * @param  string personName : 
 * @param  string name       : 
 * @return int               : returns the index where name was found (if not found -1 will be)
 */
int isMatching(string personName, string name)
{
    bool found;
    for (size_t i = 0; i < personName.length(); i++)
    {
        if (personName[i] == name[0])
        {
            found = true;
            for (size_t j = 1; j < name.length(); j++)
            {
                if (personName[i + j] != name[j])
                {
                    found = false;
                }
            }
            if (found) return i;
        }
    }
    return -1;
}
/**
 * @param  list<Check> checks : list of checks
 * @param  string name        : name you want to search in checks
 * @return list<Check>        : returns list of matching checks
 */
list<Check> searchByPersonName(list<Check> checks, string name)
{
    for (list<Check>::iterator i = checks.begin(); i != checks.end();)
    {
        if (isMatching((*i).personName, name) == -1)
        {
            checks.erase(i++);
            continue;
        }
        i++;
    }
    return checks;
}
/**
 * @param  list<Check> checks : list of checks
 * @param  string number      : check number you want to search for
 * @return Check              : returns the matching check
 */
Check searchByNumber(list<Check> checks, string number)
{
    for (list<Check>::iterator i = checks.begin(); i != checks.end();)
    {
        if ((*i).number != number)
        {
            checks.erase(i++);
            continue;
        }
        i++;
    }
    return (checks.size() == 1) ? checks.front() : failSearch;
}
/**
 * @param  list<Check> checks : list of checks
 * @param  Date startDate     : start of date interval
 * @param  Date endDate       : end of date interval
 * @return list<Check>        : returns list of matching checks
 */
list<Check> searchByDate(list<Check> checks, Date startDate, Date endDate)
{
    for (list<Check>::iterator i = checks.begin(); i != checks.end();)
    {
        if ((*i).date.year < startDate.year || (*i).date.year > endDate.year)
        {
            checks.erase(i++);
            continue;
        }
        else if (((*i).date.year == startDate.year && (*i).date.month < startDate.month) || ((*i).date.year == endDate.year && (*i).date.month > endDate.month))
        {
            checks.erase(i++);
            continue;
        }
        else if (((*i).date.year == startDate.year && (*i).date.month == startDate.month && (*i).date.day < startDate.day) || ((*i).date.year == endDate.year && (*i).date.month == endDate.month && (*i).date.day > endDate.day))
        {
            checks.erase(i++);
            continue;
        }
        i++;
    }
    return checks;
}
/**
 * @param  list<Check> checks  : list of checks
 * @param  large_t startAmount
 * @param  large_t endAmount
 * @return list<Check>         : returns list of matching checks
 */
list<Check> searchByAmount(list<Check> checks, large_t startAmount, large_t endAmount)
{
    for (list<Check>::iterator i = checks.begin(); i != checks.end();)
    {
        if ((*i).amount < startAmount || (*i).amount > endAmount)
        {
            checks.erase(i++);
            continue;
        }
        i++;
    }
    return checks;
}
/**
 * shows the check you have given
 * @param  Check check :
 */
void showChecks(Check check)
{
    cout << "Check number: ";
    SetConsoleTextAttribute(console, Blue);
    cout << check.number;
    SetConsoleTextAttribute(console, Def);
    cout << ", Amount: ";
    SetConsoleTextAttribute(console, Red);
    cout << check.amount;
    SetConsoleTextAttribute(console, Def);
    cout << ", Person name: ";
    SetConsoleTextAttribute(console, Green);
    cout << check.personName;
    SetConsoleTextAttribute(console, Def);
    cout << ", Year: ";
    SetConsoleTextAttribute(console, Yellow);
    cout << check.date.year;
    SetConsoleTextAttribute(console, Def);
    cout << ", Mounth: ";
    SetConsoleTextAttribute(console, Yellow);
    cout << check.date.month;
    SetConsoleTextAttribute(console, Def);
    cout << ", Day: ";
    SetConsoleTextAttribute(console, Yellow);
    cout << check.date.day << endl;
    SetConsoleTextAttribute(console, Def);
}
/**
 * shows list of checks you have given
 * @param  list<Check> checks : list of checks
 */
void showChecks(list<Check> checks)
{
    size_t index = 1;
    for (Check check : checks)
    {
        cout << index << ".Check number: ";
        SetConsoleTextAttribute(console, Blue);
        cout << check.number;
        SetConsoleTextAttribute(console, Def);
        cout << ", Amount: ";
        SetConsoleTextAttribute(console, Red);
        cout << check.amount;
        SetConsoleTextAttribute(console, Def);
        cout << ", Person name: ";
        SetConsoleTextAttribute(console, Green);
        cout << check.personName;
        SetConsoleTextAttribute(console, Def);
        cout << ", Year: ";
        SetConsoleTextAttribute(console, Yellow);
        cout << check.date.year;
        SetConsoleTextAttribute(console, Def);
        cout << ", Mounth: ";
        SetConsoleTextAttribute(console, Yellow);
        cout << check.date.month;
        SetConsoleTextAttribute(console, Def);
        cout << ", Day: ";
        SetConsoleTextAttribute(console, Yellow);
        cout << check.date.day << endl;
        SetConsoleTextAttribute(console, Def);
        index++;
    }
}
/**
 * shows list of checks you have given and highlights the given part of person name in check's person name 
 * @param  {list<Check>} checks    : list of checks
 * @param  {string} highlight      : name you want to highlight
 * @param  {BackgroundColor} color : color of highlight
 */
void showChecks(list<Check> checks, string highlight, BackgroundColor color)
{
    size_t startMatch, index = 1;
    for (Check check : checks)
    {
        startMatch = isMatching(check.personName, highlight);
        cout << index << ".Check number: ";
        SetConsoleTextAttribute(console, Blue);
        cout << check.number;
        SetConsoleTextAttribute(console, Def);
        cout << ", Amount: ";
        SetConsoleTextAttribute(console, Red);
        cout << check.amount;
        SetConsoleTextAttribute(console, Def);
        cout << ", Person name: ";
        SetConsoleTextAttribute(console, Gray);
        for (size_t i = 0; i < check.personName.length(); i++)
        {
            if (startMatch == i)
            {
                SetConsoleTextAttribute(console, color);
            }
            if (startMatch + highlight.length() == i)
            {
                SetConsoleTextAttribute(console, Gray);
            }
            cout << check.personName[i];
        }
        SetConsoleTextAttribute(console, Def);
        cout << ", Year: ";
        SetConsoleTextAttribute(console, Yellow);
        cout << check.date.year;
        SetConsoleTextAttribute(console, Def);
        cout << ", Mounth: ";
        SetConsoleTextAttribute(console, Yellow);
        cout << check.date.month;
        SetConsoleTextAttribute(console, Def);
        cout << ", Day: ";
        SetConsoleTextAttribute(console, Yellow);
        cout << check.date.day << endl;
        SetConsoleTextAttribute(console, Def);
        index++;
    }
}
/**
 * shows availble options for checks
 */
void showOptions()
{
    cout << "Enter one of options number:" << endl;
    cout << "1.New check" << endl;
    cout << "2.Edit check" << endl;
    cout << "3.Delete check" << endl;
    cout << "4.Search check by number" << endl;
    cout << "5.Search check by name" << endl;
    cout << "6.Search check by date" << endl;
    cout << "7.Search check by amount" << endl;
    cout << "8.List all checks" << endl;
    cout << "9.Exit" << endl;
}
/**
 * gets all of informations about a check
 * @param list<Check> : list of checks
 * @return Check  : rwturns structure of a check
 */
Check getCheckData(list<Check> checks)
{
    string number, personName, amount, year, month, day;
    Check tempCheck;
    while (true)
    {
        cout << "Enter number of check: ";
        getline(cin, number);
        if (isNumber(number))
        {
            tempCheck = searchByNumber(checks, number);
            if (isSameCheck(tempCheck, failSearch)) break;
            SetConsoleTextAttribute(console, Red);
            cout << "The number is already exists in list of checks!" << endl;
            SetConsoleTextAttribute(console, Def);
        }
        else
        {
            SetConsoleTextAttribute(console, Red);
            cout << "Invalid check number: please enter a number!" << endl;
            SetConsoleTextAttribute(console, Def);
        }   
    }
    while (true)
    {
        cout << "Enter amount of check: ";
        getline(cin, amount);
        if (isNumber(amount) && amount.length() <= maxAmountLength) break;
        SetConsoleTextAttribute(console, Red);
        cout << "Invalid check amount: please enter a number that at most has 18 digits!" << endl;
        SetConsoleTextAttribute(console, Def);
    }
    cout << "Enter the name of person check is being writen for: ";
    getline(cin, personName);
    while (true)
    {
        cout << "Enter year of check: ";
        getline(cin, year);
        if (isNumber(year) && year.length() == 4) break;
        SetConsoleTextAttribute(console, Red);
        cout << "Invalid check year: please enter a 4 digit number!" << endl;
        SetConsoleTextAttribute(console, Def);
    }
    while (true)
    {
        cout << "Enter month of check: ";
        getline(cin, month);
        if (isNumber(month) && month.length() <= 2 && stoi(month) <= 12 && stoi(month) >= 1) break;
        SetConsoleTextAttribute(console, Red);
        cout << "Invalid check month: please enter a number between 1 and 12!" << endl;
        SetConsoleTextAttribute(console, Def);
    }
    while (true)
    {
        cout << "Enter day of check: ";
        getline(cin, day);
        if (isNumber(day) && day.length() <= 2 && stoi(day) <= 31 && stoi(day) >= 1) break;
        SetConsoleTextAttribute(console, Red);
        cout << "Invalid check day: please enter a number between 1 and 31!" << endl;
        SetConsoleTextAttribute(console, Def);
    }
    return {number, stringToInt(amount), personName, {(small_t) stoi(day), (small_t) stoi(month), (small_t) stoi(year)}};
}
/**
 * shows availble options for editing checks
 */
void showEditOptions()
{
    cout << "Enter one of options number:" << endl;
    cout << "1.Edit check by number" << endl;
    cout << "2.Edit check by name" << endl;
    cout << "3.Edit check by date" << endl;
    cout << "4.Edit check by amount" << endl;
    cout << "5.Cancle" << endl;
}
/**
 * edits informations of intended check
 * @param  list<Check> checks : lit of check
 * @param  string checkNumber : number of intended check
 */
void editByNumber(list<Check>& checks, string number)
{
    deleteByNumber(checks, number);
    checks.push_back(getCheckData(checks));
    // Check check;
    // for (list<Check>::iterator i = checks.begin(); i != checks.end(); i++)
    // {
    //     if ((*i).number == checkNumber)
    //     {
    //         check = getCheckData(checks);
    //         (*i).number = check.number;
    //         (*i).amount = check.amount;
    //         (*i).personName = check.personName;
    //         (*i).date = check.date;
    //         return;
    //     }
    // }
}
/**
 * gets a date interval
 * @param  Date startDate : 
 * @param  Date endDate   : 
 */
void getDateInterval(Date& startDate, Date& endDate)
{
    string year, month, day;
    while (true)
    {
        cout << "Enter start year of date interval: ";
        getline(cin, year);
        if (isNumber(year) && year.length() == 4) break;
        SetConsoleTextAttribute(console, Red);
        cout << "Invalid year: please enter a 4 digit number!" << endl;
        SetConsoleTextAttribute(console, Def);
    }
    while (true)
    {
        cout << "Enter start month of date interval: ";
        getline(cin, month);
        if (isNumber(month) && month.length() <= 2 && stoi(month) <= 12 && stoi(month) >= 1) break;
        SetConsoleTextAttribute(console, Red);
        cout << "Invalid month: please enter a number between 1 and 12!" << endl;
        SetConsoleTextAttribute(console, Def);
    }
    while (true)
    {
        cout << "Enter start day of date interval: ";
        getline(cin, day);
        if (isNumber(day) && day.length() <= 2 && stoi(day) <= 31 && stoi(day) >= 1) break;
        SetConsoleTextAttribute(console, Red);
        cout << "Invalid day: please enter a number between 1 and 31!" << endl;
        SetConsoleTextAttribute(console, Def);
    }
    startDate.year = (small_t) stoi(year);
    startDate.month = (small_t) stoi(month);
    startDate.day = (small_t) stoi(day);
    while (true)
    {
        cout << "Enter end year of date interval: ";
        getline(cin, year);
        if (isNumber(year) && year.length() == 4) break;
        SetConsoleTextAttribute(console, Red);
        cout << "Invalid year: please enter a 4 digit number!" << endl;
        SetConsoleTextAttribute(console, Def);
    }
    while (true)
    {
        cout << "Enter end month of date interval: ";
        getline(cin, month);
        if (isNumber(month) && month.length() <= 2 && stoi(month) <= 12 && stoi(month) >= 1) break;
        SetConsoleTextAttribute(console, Red);
        cout << "Invalid month: please enter a number between 1 and 12!" << endl;
        SetConsoleTextAttribute(console, Def);
    }
    while (true)
    {
        cout << "Enter end day of date interval: ";
        getline(cin, day);
        if (isNumber(day) && day.length() <= 2 && stoi(day) <= 31 && stoi(day) >= 1) break;
        SetConsoleTextAttribute(console, Red);
        cout << "Invalid day: please enter a number between 1 and 31!" << endl;
        SetConsoleTextAttribute(console, Def);
    }
    endDate.year = (small_t) stoi(year);
    endDate.month = (small_t) stoi(month);
    endDate.day = (small_t) stoi(day);
}
/**
 * shows availble options for deleting checks
 */
void showDeleteOptions()
{
    cout << "Enter one of options number:" << endl;
    cout << "1.Delete check by number" << endl;
    cout << "2.Delete check by name" << endl;
    cout << "3.Delete check by date" << endl;
    cout << "4.Delete check by amount" << endl;
    cout << "5.Cancle" << endl;
}
/**
 * deletes your intended check
 * @param  list<Check> checks : list of checks
 * @param  string number      : number of intended check
 */
void deleteByNumber(list<Check>& checks, string number)
{
    for (list<Check>::iterator i = checks.begin(); i != checks.end(); i++)
    {
        if ((*i).number == number)
        {
            checks.erase(i);
            return;
        }
    }
}
/**
 * sorts list of checks acording to its date
 * @param  list<Check> checks : list of checks
 */
void sortByDate(list<Check>& checks)
{
    Check tempCheck;
    for (list<Check>::iterator i = checks.begin(); i != checks.end(); i++)
    {
        for (list<Check>::iterator j = i; j != checks.end(); j++)
        {
            if ((*i).date.year > (*j).date.year)
            {
                tempCheck = *i;
                *i = *j;
                *j = tempCheck;
            }
            else if ((*i).date.year == (*j).date.year && (*i).date.month > (*j).date.month)
            {
                tempCheck = *i;
                *i = *j;
                *j = tempCheck;
            }
            else if ((*i).date.year == (*j).date.year && (*i).date.month == (*j).date.month && (*i).date.day > (*j).date.day)
            {
                tempCheck = *i;
                *i = *j;
                *j = tempCheck;
            }
        }
    }
}
/**
 * @param  Check firstCheck 
 * @param  Check secondCheck
 * @return bool              : returns the result of comparison
 */
bool isSameCheck(Check firstCheck, Check secondCheck)
{
    if (firstCheck.number != secondCheck.number) return false;
    if (firstCheck.personName != secondCheck.personName) return false;
    if (firstCheck.amount != secondCheck.amount) return false;
    if (firstCheck.date.year != secondCheck.date.year) return false;
    if (firstCheck.date.month != secondCheck.date.month) return false;
    if (firstCheck.date.day != secondCheck.date.day) return false;
    return true;
}
/**
 * @param  string number
 * @return bool          : returns true if all of charecters be digits
 */
bool isNumber(string number)
{
    for (size_t i = 0; i < number.length(); i++)
    {
        if (number[i] < 48 || number[i] > 57) return false;
    }
    return true;
}
/**
 * @param  string number
 * @return unsigned long long int
 */
large_t stringToInt(string number)
{
    large_t num = 0;
    for (size_t i = 0; i < number.length(); i++)
    {
        num += (number[i] - '0') * pow(10, number.length() - i - 1);
    }
    return num;
}
/**
 * loads check informations to list
 * @param  list<Check> checks : a list to load checks from file to
 */
void readChecks(list<Check>& checks)
{
    fstream file;
    Check check;
    file.open(fileName, ios::in | ios::binary);
    while (file.read((char*) &check, sizeof(check)))
    {
        checks.push_back(check);
    }
    file.close();
}
/**
 * @param  list<Check> checks : list of checks you want to save
 */
void writeChecks(list<Check> checks)
{
    fstream file;
    Check check;
    file.open(fileName, ios::out | ios::binary | ios::trunc);
    for (list<Check>::iterator i = checks.begin(); i != checks.end(); i++)
    {
        check = *i;
        file.write((char*) &check, sizeof(check));
    }
    file.close();
}
/**
 * gets a valid option from input stream
 * @param  int option       
 * @param  int startNumber  
 * @param  int endNumber    
 */
void getOption(int& option, int startNumber, int endNumber)
{
    string optionStr;
    while (true)
    {
        cout << "Option: ";
        getline(cin, optionStr);
        if (optionStr.length() > 0 && isNumber(optionStr) && optionStr.length() <= 2 && stoi(optionStr) >= startNumber && stoi(optionStr) <= endNumber)
        {
            option = stoi(optionStr);
            return;
        }
        SetConsoleTextAttribute(console, Red);
        cout << "Invalid option: please enter number of one of options above!" << endl;
        SetConsoleTextAttribute(console, Def);
    }
}
/**
 * @param  string number
 */
void getNumber(string& number)
{
    while (true)
    {
        cout << "Enter check's number: ";
        getline(cin, number);
        if (isNumber(number)) break;
        SetConsoleTextAttribute(console, Red);
        cout << "Invalid check number: please enter a number!" << endl;
        SetConsoleTextAttribute(console, Def);
    }   
}
/**
 * @param  large_t sAmount : start amount
 * @param  large_t eAmount : end amount
 */
void getAmountInterval(large_t& sAmount, large_t& eAmount)
{
    string startAmount, endAmount;
    while (true)
    {
        cout << "Enter start amount of interval: ";
        getline(cin, startAmount);
        if (isNumber(startAmount) || startAmount.length() <= maxAmountLength) break;
        SetConsoleTextAttribute(console, Red);
        cout << "Invalid amount: please enter a number that at most has 18 digits!" << endl;
        SetConsoleTextAttribute(console, Def);
    }
    sAmount = stringToInt(startAmount);
    while (true)
    {
        cout << "Enter end amount of interval: ";
        getline(cin, endAmount);
        if (isNumber(endAmount) || endAmount.length() <= maxAmountLength) break;
        SetConsoleTextAttribute(console, Red);
        cout << "Invalid amount: please enter a number that at most has 18 digits!" << endl;
        SetConsoleTextAttribute(console, Def);
    }
    eAmount = stringToInt(endAmount);
}
/**
 * shows yes and no options with red and green color
 */
void showYesNo()
{
    cout << "1.";
    SetConsoleTextAttribute(console, Red);
    cout << "Yes" << endl;
    SetConsoleTextAttribute(console, Def);
    cout << "2.";
    SetConsoleTextAttribute(console, Green);
    cout << "No" << endl;
    SetConsoleTextAttribute(console, Def);
}