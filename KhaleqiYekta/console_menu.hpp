/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file console_menu.cpp
 * @brief A library which makes creating console menus easy.
 */

/** External Libraries **/
#include <iostream>
#include <string>
#include "console.hpp"
#include "rang.hpp"

/** Namespaces **/
using namespace std;

/** Constants **/


/** Other Variables **/


/** Function Declarations **/

class ConsoleMenu
{
public:
    string title;
    string[] items;

    ConsoleMenu(string title/*, string[] items*/)
    {
        title = this->title;
        //items = this->items;
        clearConsole();
        printSeparatorLine('-',2);
    }
};
