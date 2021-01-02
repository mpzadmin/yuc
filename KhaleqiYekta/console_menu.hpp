/*
 * Copyright © 2020 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 * Creation Date: 2020-12-29
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
