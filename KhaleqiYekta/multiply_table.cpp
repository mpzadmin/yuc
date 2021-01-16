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

const int width = 10;
const int height = 10;

int main(int argc, char const * argv[])
{

    system("cls");

    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            cout << i * j << " ";
        }

        cout << endl;
    }

    return 0;
}