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

int main()
{
    char character;

    while (true)
    {
        cout << "Enter a character (q to quit): ";
        cin >> character;
        if (character == 'q')
        {
            break;
        }
        cout << endl << "Character: " << character << endl;
    }
}