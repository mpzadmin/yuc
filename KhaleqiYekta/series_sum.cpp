/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

#include <iostream>

using namespace std;

int main()
{
    int n;
    float nthPart, result = 0, factorial = 1;

    // Factorial is float so that the calculations with the other floats go fine...

    system("cls");

    cout << "Enter a positive number: ";
    cin >> n;

    if (n < 1)
    {
        cout << "Invalid number!";
        return 0;
    }
    if (n > 999)
    {
        cout << "Big numbers make CPU sick!";
        return 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            factorial *= j;
        }

        nthPart = 1 / factorial;

        result += nthPart;

        // Reset factorial for the next use
        factorial = 1;
    }

    cout << "Result: " << result << endl;

    return 0;
}