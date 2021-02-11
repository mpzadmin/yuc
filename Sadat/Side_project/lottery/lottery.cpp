/**
 * copyright (c) 2021-2022
 * pouya.s2781@gmail.com
 * 
 * @file "lottery.cpp"
 * @file "lottery.hpp"
 * a program for determining lottery winners
 */

#include <iostream>
#include <time.h>
#include <list>
#include <windows.h>
#include "lottery.hpp"

using namespace std;

int main()
{
    /* Variable decleration */
    int option, serial, count;
    list<int> serials;
    srand(time(0));

    // Reading serials from file
    readSerials(serials);
    while(true)
    {
        system("cls");
        showOptions();
        getOption(option, 1, 3);
        if (option == 3) return 0;
        switch (option)
        {
            // Adding new serials
            case 1:
                system("cls");
                while(true)
                {
                    getSerial(serial);
                    if (serial == 0) break;
                    serials.push_back(serial);
                }
                writeSerials(serials);
                break;
            // Taking out random serial numbers
            case 2:
                system("cls");
                if (serials.size() == 0)
                {
                    SetConsoleTextAttribute(console, 4);
                    cout << "There is no lottery card!" << endl;
                    SetConsoleTextAttribute(console, 7);
                    break;
                }
                getCount(count, 1, serials.size());
                showRandomLottery(serials, count);
                break;
            default:
                break;
        }
        system("pause");
    }
}