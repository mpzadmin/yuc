/**
 * copyright (c) 2021-2022
 * pouya.s2781@gmail.com
 * 
 * @file "lottery.hpp"
 * a usefull library for lettery program
 */

#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include <list>
#include <windows.h>
#include <iomanip>

using namespace std;

/* Variable and function decleration */
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
const string fileName = "serials.dat";
fstream file;
void showOptions();
void getSerial(int& serial);
bool isNumber(string number);
void readSerials(list<int>& serials);
void writeSerials(list<int> serials);
void showRandomLottery(list<int> serials, int count);
void getCount(int& count, int startNumber, int endNumber);
void getOption(int& option, int startNumber, int endNumber);

// Shows program options
void showOptions()
{
    cout << "1.Entering lottery card information" << endl;
    cout << "2.Lottery" << endl;
    cout << "3.Exit" << endl;
}
// Gets a valid option from user
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
        SetConsoleTextAttribute(console, 4);
        cout << "Invalid option: please enter number of one of options above!" << endl;
        SetConsoleTextAttribute(console, 7);
    }
}
// Checks if a string contains number
bool isNumber(string number)
{
    for (size_t i = 0; i < number.length(); i++)
    {
        if (number[i] < 48 || number[i] > 57) return false;
    }
    return true;
}
// Gets a valid serial number
void getSerial(int& serial)
{
    string serialStr;
    while(true)
    {
        SetConsoleTextAttribute(console, 7);
        cout << "Please enter a serial number: ";
        getline(cin, serialStr);
        if (serialStr.length() > 0 && isNumber(serialStr) && serialStr.length() <= 9)
        {
            serial = stoi(serialStr);
            break;
        }
        SetConsoleTextAttribute(console, 4);
        cout << "Invalid input: enter a serial number with at most 9 digits" << endl;
    }
}
// Writes the serials on serials.dat
void writeSerials(list<int> serials)
{
    file.open(fileName, ios::out | ios::binary | ios::trunc);

    for (list<int>::iterator i = serials.begin(); i != serials.end(); i++)
    {
        file.write((char*) &(*i), sizeof(int));
    }
    file.close();
}
// Reads the serials from serials.dat
void readSerials(list<int>& serials)
{
    int serial;
    file.open(fileName, ios::in | ios::binary);

    while(file.read((char*) &serial, sizeof(int)))
    {
        serials.push_back(serial);
    }
    file.close();
}
// Gets a valid count for taking out lottery winners
void getCount(int& count, int startNumber, int endNumber)
{
    string countStr;
    while (true)
    {
        cout << "Enter the count of lottery you want to take out: ";
        getline(cin, countStr);
        if (countStr.length() > 0 && isNumber(countStr) && countStr.length() <= 9 && stoi(countStr) >= startNumber && stoi(countStr) <= endNumber)
        {
            count = stoi(countStr);
            return;
        }
        SetConsoleTextAttribute(console, 4);
        cout << "Invalid option: please enter a number between " << startNumber << " and " << endNumber << "!" << endl;
        SetConsoleTextAttribute(console, 7);
    }
}
// Shows random serials from all of serials
void showRandomLottery(list<int> serials, int count)
{
    int randomNumber;
    list<int>::iterator serialsItr;
    for (size_t i = 0; i < count; i++)
    {
        randomNumber = rand() % serials.size();
        serialsItr = serials.begin();
        advance(serialsItr, randomNumber);
        cout << *serialsItr << endl;
        serials.erase(serialsItr);
    }
}