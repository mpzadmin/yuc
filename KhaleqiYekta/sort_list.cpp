/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/** External Libraries **/
#include <iostream>
#include <string>

/** Namespaces **/
using namespace std;

/** Constants **/
const string strRequestCount = "Enter the count of the numbers: ";
const string strResultTitle = "The sorted list is: ";
const string strErrorInvalidResult = "Invalid count!";

/** Function Declarations **/
void sortList(int* list, const size_t &len);
void printList(const int* list, const size_t &len);
int askForInt(const string& titleToPrint);
void clearConsole();

// Program's Entry Point
int main()
{
    size_t listSize;
    int* list = new int;

    clearConsole();

    listSize = askForInt(strRequestCount);

    if (listSize < 1 || listSize > 999)
    {
        cout << strErrorInvalidResult << endl;
        return 0;
    }

    for (size_t i = 0; i < listSize; ++i)
    {
        list[i] = askForInt("Enter number " + to_string(i+1) + ": ");
    }

    sortList(list, listSize);

    cout << strResultTitle;
    printList(list, listSize);

    return 0;
}

// Sorts the list
void sortList(int* list, const size_t &len)
{
    for(size_t i = 0; i < len; ++i)
    {
        for (size_t j = i+1; j < len; ++j)
        {
            if (list[i] > list[j])
            {
                swap(list[i], list[j]);
            }
        }
    }
}

// Prints the list
void printList(const int* list, const size_t &len)
{
    string result;

    for (size_t i = 0; i < len; ++i)
    {
        result += to_string(list[i]);

        if (i != len-1)
        {
           result += ", ";
        }
    }

    cout << result << endl;
}

// Returns an integer which is requested from user, then goes to a new line after the process is done.
int askForInt(const string &titleToPrint)
{
    int data;

    cout << titleToPrint;
    cin >> data;
    cout << endl;

    return data;
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
