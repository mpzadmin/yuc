/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

#include <iostream>
#include <string>

using namespace std;

const int delay = 100000000;

int main()
{
    string userStr;

    system("cls");

    cout << "Enter a text: ";
    getline(cin, userStr);

    cout << endl;

    // Start printing
    for (int i = 0; i < userStr.length(); ++i)
    {
        for (int j = 0; j < delay; ++j)
        {
            // Adds delay to the process of printing
        }

        // Print a character
        cout << userStr[i];
    }

    cout << endl;

    return 0;
}