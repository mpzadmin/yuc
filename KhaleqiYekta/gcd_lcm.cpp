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
    // INITIALIZATION
    int n1, n2, gcd, bigger, smaller;

    system("cls");

    cout << "Enter two positive numbers: ";
    cin >> n1 >> n2;

    if (n1 < 1 || n2 < 2)
    {
        cout << "Invalid number(s)!";
        return 0;
    }

    if (n2 > n1)
    {
        bigger = n2;
        smaller = n1;
    }
    else
    {
        bigger = n1;
        smaller = n2;
    }

    // GCD
    gcd = smaller;

    while (bigger % smaller != 0)
    {
        gcd = bigger % smaller;

        bigger = smaller;
        smaller = gcd;
    }

    // LCM
    // Bigger needs to turn to its original value
    bigger = (n1 > n2) ? n1 : n2;

    while (bigger % n1 != 0 || bigger % n2 != 0)
    {
        bigger++;
    }

    // Bigger is now LCM

    // RESULTS
    cout << "Greatest Common Divisor: " << gcd << endl;
    cout << "Least Common Multiple: " << bigger << endl;

    return 0;
}
