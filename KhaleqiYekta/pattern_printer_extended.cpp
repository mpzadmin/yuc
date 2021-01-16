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
    int n;

    system("cls");

    cout << "Enter the count of pattern lines: ";
    cin >> n;

    if (n < 1)
    {
        cout << "Invalid number!";
        return 0;
    }
    if (n > 9999)
    {
        cout << "Big numbers make CPU sick!";
        return 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        // Left Spaces
        for (int j = (n - i); j > 0; --j)
        {
            cout << "    ";
        }
        // Left Part
        for (int j = i; j > 0; --j)
        {
            cout << j << "   ";
        }
        // Right Part
        for (int j = 1; j <= i; ++j)
        {
            if (j == 1)
            {
                continue;
            }

            cout << j << "   ";
        }

        cout << endl;
    }

    return 0;
}