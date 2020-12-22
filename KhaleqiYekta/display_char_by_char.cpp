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

/** Function Declrations **/
void display(string* text, int len);

// Program's Entry Point
int main()
{
    string txt = "Hello";

    clearConsole();

    display(&txt, 5);

    return 0;
}

// Displays a string (Each character in a new line)
void display(string* ptr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << (*ptr)[i] << endl;
    }
}
