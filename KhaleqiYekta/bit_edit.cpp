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
    int num;

    system("cls");

    cout << "Enter a number: ";
    cin >> num;

    num |= 0100001011000;
    num &= 00111111011;

    cout << endl << "Result: " << num << endl;

    return 0;
}
