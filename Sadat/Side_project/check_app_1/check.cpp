/**
 * copyright (c) 2021-2022
 * Pouya Sadat
 * pouya.s2781@gmail.com
 * 
 * @file "check.cpp"
 * this is a full programm for managing your checks
 * check.hpp library is included in this program
 */

#include <iostream>
#include <list>
#include "check.hpp"

using namespace std;

int main()
{
    // Variable decleration
    list<Check> checks, tempChecks;
    list<Check>::iterator tempItr;
    Check tempCheck;
    string personName, number;
    large_t amount, startAmount, endAmount;
    int option;
    Date startDate, endDate;

    while (true)
    {
        system("cls");
        showOptions();
        getOption(option, 1, 9);
        if (option == 9) return 0;
        switch (option)
        {
            // Adding new check
            case 1:
                system("cls");
                checks.push_back(getCheckData(checks));
                break;
            // Editing existing checks
            case 2:
                system("cls");
                showEditOptions();
                getOption(option, 1, 5);
                if (option == 5) break;
                switch (option)
                {
                    // Finding check by number
                    case 1:
                        getNumber(number);
                        tempCheck = searchByNumber(checks, number);
                        if (!isSameCheck(tempCheck, failSearch))
                        {
                            showChecks(tempCheck);
                        }
                        else
                        {
                            SetConsoleTextAttribute(console, Red);
                            cout << "Coudn't find any checks with your given number!" << endl;
                            SetConsoleTextAttribute(console, Def);
                            break;
                        }
                        cout << "Are you sure you want to edit this check:" << endl;
                        showYesNo();
                        getOption(option, 1, 2);
                        if (option == 1) editByNumber(checks, number);
                        break;
                    // Finding check by person name
                    case 2:
                        cout << "Enter the name of person check was writen for: ";
                        getline(cin, personName);
                        tempChecks = searchByPersonName(checks, personName);
                        if (tempChecks.size() != 0)
                        {
                            showChecks(tempChecks, personName, Green);
                        }
                        else
                        {
                            SetConsoleTextAttribute(console, Red);
                            cout << "Coudn't find any checks with your given name!" << endl;
                            SetConsoleTextAttribute(console, Def);
                            break;
                        }
                        cout << "Enter which check you want to edit." << endl;
                        getOption(option, 1, tempChecks.size());
                        tempItr = tempChecks.begin();
                        advance(tempItr, option - 1);
                        showChecks(searchByNumber(tempChecks, (*tempItr).number));
                        cout << "Are you sure you want to edit this check:" << endl;
                        showYesNo();
                        getOption(option, 1, 2);
                        if (option == 1) editByNumber(checks, (*tempItr).number);
                        break;
                    // Finding check by date interval
                    case 3:
                        getDateInterval(startDate, endDate);
                        tempChecks = searchByDate(checks, startDate, endDate);
                        if (tempChecks.size() != 0)
                        {
                            sortByDate(tempChecks);
                            showChecks(tempChecks);
                        }
                        else
                        {
                            SetConsoleTextAttribute(console, Red);
                            cout << "Coudn't find any checks with your given date interval!" << endl;
                            SetConsoleTextAttribute(console, Def);
                            break;
                        }
                        cout << "Enter which check you want to edit." << endl;
                        getOption(option, 1, tempChecks.size());
                        tempItr = tempChecks.begin();
                        advance(tempItr, option - 1);
                        showChecks(searchByNumber(tempChecks, (*tempItr).number));
                        cout << "Are you sure you want to edit this check:" << endl;
                        showYesNo();
                        getOption(option, 1, 2);
                        if (option == 1) editByNumber(checks, (*tempItr).number);
                        break;
                    // Finding check by amount interval
                    case 4:
                        getAmountInterval(startAmount, endAmount);
                        tempChecks = searchByAmount(checks, startAmount, endAmount);
                        if (tempChecks.size() != 0)
                        {
                            sortByDate(tempChecks);
                            showChecks(tempChecks);
                        }
                        else
                        {
                            SetConsoleTextAttribute(console, Red);
                            cout << "Coudn't find any checks with your given amount interval!" << endl;
                            SetConsoleTextAttribute(console, Def);
                            break;
                        }
                        cout << "Enter which check you want to edit." << endl;
                        getOption(option, 1, tempChecks.size());
                        tempItr = tempChecks.begin();
                        advance(tempItr, option - 1);
                        showChecks(searchByNumber(tempChecks, (*tempItr).number));
                        cout << "Are you sure you want to edit this check:" << endl;
                        showYesNo();
                        getOption(option, 1, 2);
                        if (option == 1) editByNumber(checks, (*tempItr).number);
                        break;
                    default:
                        break;
                }
                break;
            // Deleting existing checks
            case 3:
                system("cls");
                showDeleteOptions();
                getOption(option, 1, 5);
                if (option == 5) break;
                switch (option)
                {
                    // Finding check by number
                    case 1:
                        getNumber(number);
                        tempCheck = searchByNumber(checks, number);
                        if (!isSameCheck(tempCheck, failSearch))
                        {
                            showChecks(tempCheck);
                        }
                        else
                        {
                            SetConsoleTextAttribute(console, Red);
                            cout << "Coudn't find any checks with your given number!" << endl;
                            SetConsoleTextAttribute(console, Def);
                            break;
                        }
                        cout << "Are you sure you want to delete this check:" << endl;
                        showYesNo();
                        getOption(option, 1, 2);
                        if (option == 1) deleteByNumber(checks, number);
                        break;
                    // Finding check by person name
                    case 2:
                        cout << "Enter the name of person check was writen for: ";
                        getline(cin, personName);
                        tempChecks = searchByPersonName(checks, personName);
                        if (tempChecks.size() != 0)
                        {
                            showChecks(tempChecks, personName, Green);
                        }
                        else
                        {
                            SetConsoleTextAttribute(console, Red);
                            cout << "Coudn't find any checks with your given name!" << endl;
                            SetConsoleTextAttribute(console, Def);
                            break;
                        }
                        cout << "Enter which check you want to edit." << endl;
                        getOption(option, 1, tempChecks.size());
                        tempItr = tempChecks.begin();
                        advance(tempItr, option - 1);
                        cout << "Are you sure you want to delete this check:" << endl;
                        showYesNo();
                        getOption(option, 1, 2);
                        if (option == 1) deleteByNumber(checks, (*tempItr).number);
                        break;
                    // Finding check by date interval
                    case 3:
                        getDateInterval(startDate, endDate);
                        tempChecks = searchByDate(checks, startDate, endDate);
                        if (tempChecks.size() != 0)
                        {
                            sortByDate(tempChecks);
                            showChecks(tempChecks);
                        }
                        else
                        {
                            SetConsoleTextAttribute(console, Red);
                            cout << "Coudn't find any checks with your given date interval!" << endl;
                            SetConsoleTextAttribute(console, Def);
                            break;
                        }
                        cout << "Enter which check you want to edit." << endl;
                        getOption(option, 1, tempChecks.size());
                        tempItr = tempChecks.begin();
                        advance(tempItr, option - 1);
                        cout << "Are you sure you want to delete this check:" << endl;
                        showYesNo();
                        getOption(option, 1, 2);
                        if (option == 1) deleteByNumber(checks, (*tempItr).number);
                        break;
                    // Finding check by amount interval
                    case 4:
                        getAmountInterval(startAmount, endAmount);
                        tempChecks = searchByAmount(checks, startAmount, endAmount);
                        if (tempChecks.size() != 0)
                        {
                            sortByDate(tempChecks);
                            showChecks(tempChecks);
                        }
                        else
                        {
                            SetConsoleTextAttribute(console, Red);
                            cout << "Coudn't find any checks with your given amount interval!" << endl;
                            SetConsoleTextAttribute(console, Def);
                            break;
                        }
                        cout << "Enter which check you want to delete." << endl;
                        getOption(option, 1, tempChecks.size());
                        tempItr = tempChecks.begin();
                        advance(tempItr, option - 1);
                        showChecks(searchByNumber(tempChecks, (*tempItr).number));
                        cout << "Are you sure you want to delete this check:" << endl;
                        showYesNo();
                        getOption(option, 1, 2);
                        if (option == 1) deleteByNumber(checks, (*tempItr).number);
                        break;
                    default:
                        break;
                }
                break;
            // Finding check by number
            case 4:
                system("cls");
                getNumber(number);
                tempCheck = searchByNumber(checks, number);
                if (!isSameCheck(tempCheck, failSearch))
                {
                    showChecks(tempCheck);
                }
                else
                {
                    SetConsoleTextAttribute(console, Red);
                    cout << "Coudn't find any checks with your given number!" << endl;
                    SetConsoleTextAttribute(console, Def);
                }
                break;
            // Finding check by person name
            case 5:
                system("cls");
                cout << "Enter the name of person check was writen for: ";
                getline(cin, personName);
                tempChecks = searchByPersonName(checks, personName);
                if (tempChecks.size() != 0)
                {
                    showChecks(tempChecks, personName, Green);
                }
                else
                {
                    SetConsoleTextAttribute(console, Red);
                    cout << "Coudn't find any checks with your given name!" << endl;
                    SetConsoleTextAttribute(console, Def);
                }
                break;
            // Finding check by date interval
            case 6:
                system("cls");
                getDateInterval(startDate, endDate);
                tempChecks = searchByDate(checks, startDate, endDate);
                if (tempChecks.size() != 0)
                {
                    sortByDate(tempChecks);
                    showChecks(tempChecks);
                }
                else
                {
                    SetConsoleTextAttribute(console, Red);
                    cout << "Coudn't find any checks with your given date interval!" << endl;
                    SetConsoleTextAttribute(console, Def);
                }
                break;
            // Finding check by amount interval
            case 7:
                system("cls");
                getAmountInterval(startAmount, endAmount);
                tempChecks = searchByAmount(checks, startAmount, endAmount);
                if (tempChecks.size() != 0)
                {
                    sortByDate(tempChecks);
                    showChecks(tempChecks);
                }
                else
                {
                    SetConsoleTextAttribute(console, Red);
                    cout << "Coudn't find any checks with your given amount interval!" << endl;
                    SetConsoleTextAttribute(console, Def);
                }
                break;
            case 8:
                system("cls");
                if (checks.size() != 0)
                {
                    sortByDate(checks);
                    showChecks(checks);
                }
                else
                {
                    SetConsoleTextAttribute(console, Red);
                    cout << "Coudn't find any checks!" << endl;
                    SetConsoleTextAttribute(console, Def);
                }
                break;
            default:
                break;
        }
        system("pause");
    }
}