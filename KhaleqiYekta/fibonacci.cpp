/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

// Although Fibonacci sequence starts at 0, the homework was asking to start at 1.

#include <iostream>
#include <string>

using namespace std;

//Separator
const string sep = ",";

int main()
{
    int len, n1 = 1, n2 = 1, sum;

    system("cls");

    cout << "Enter a positive number: ";
    cin >> len;

    if (len < 1)
    {
        cout << "Invalid number!";
        return 0;
    }

    cout << "First " << len << " numbers of Fibonacci series:" << endl << n1 << sep << n2 << sep;

    sum = n1 + n2;

    for(int i = 3; i <= len; i++)
    {
        cout << sum;

        n1 = n2;
        n2 = sum;
        sum = n1 + n2;

        if (i < len)
        {
            cout << ",";
        }
    }

    return 0;
}
