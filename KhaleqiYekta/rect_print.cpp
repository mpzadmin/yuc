/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

#include <iostream>

using namespace std;

//The character used to draw horizontal lines
const char horizontalChar = '-';

//The character used to draw vertical lines
const char verticalChar = '|';

//The character which fills the rectangle
const char fillChar = ' ';

//Width of the rectangle
const int width = 10;

//Height of the rectangle
const int height = 5;

int main()
{
    //This is used to calculate how many "fillChar"s should be printed
    //in order to correctly fill the rectangle.
    const int fillLength = width - 2;

    system("cls");

    for (int i = 1; i <= height; i++)
    {
        //Determines weather it should draw a horizontal line
        bool isLine = (i == 1) || (i == height);

        //Draw a horizontal line
        if (isLine)
        {
            for (int j = 1; j <= width; j++)
            {
                cout << horizontalChar;
            }
        }
        //Draw a vertical line
        else
        {
            cout << verticalChar;

            for (int j = 1; j <= fillLength; j++)
            {
                cout << fillChar;
            }

            cout << verticalChar;
        }

        cout << endl;
    }

    return 0;
}
