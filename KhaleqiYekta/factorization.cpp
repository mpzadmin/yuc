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
    unsigned int num = 8; //The number to find the divisors of.

    for (int i = 1; i <= num; ++i)
    {
        if (num % i == 0)
        {
            cout << i << " ";
        }
    }

    return 0;
}
