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
    float len1, len2, a, p;

    system("cls");

    cout << "Enter the width and height of the rectangle: ";
    cin >> len1 >> len2;

    if (len1 <= 0 || len2 <= 0)
    {
        cout << "Value(s) need(s) to be positive!";
        return 0;
    }

    a = len1 * len2;
    p = 2 * (len1 + len2);

    cout << "Area: " << a << endl << "Perimeter: " << p << endl;

    return 0;
}