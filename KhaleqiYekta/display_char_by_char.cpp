/*
 * Copyright © 2020 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/** External Libraries **/
#include <iostream>
#include <string>
#include "console.hpp"

/** Namespaces **/
using namespace std;

/** Function Declarations **/
void display(string* ptr, size_t len);

// Program's Entry Point
int main()
{
    string txt = "Hello";

    clearConsole();

    display(&txt, txt.length());

    return 0;
}

// Displays a string (Each character in a new line)
void display(string* ptr, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        cout << (*ptr)[i] << endl;
    }
}
