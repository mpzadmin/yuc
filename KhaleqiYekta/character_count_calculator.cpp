/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/*
 * It's been told to count a CHARACTER in a string;
 * therefore, for instance, 'a' is not equal to 'A'.
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string userStr;
    char userChar;
    int charCount = 0;

    system("cls");

    // Get the string
    cout << "Enter a text: ";
    getline(cin, userStr);

    // Get the character
    cout << endl << "Now enter a character you want to know the count of: ";
    cin >> userChar;

    // Calculate the count of character in string
    for (int i = 0; i < userStr.length(); ++i)
    {
        if (userStr[i] == userChar)
        {
            charCount++;
        }
    }

    // Show the result
    switch (charCount)
    {
        case 0:
            cout << "There are no '" << userChar << "'s in '" << userStr << "'." << endl;
            break;
        case 1:
            cout << "There is one '" << userChar << "' in '" << userStr << "'." << endl;
            break;
        default:
            cout << "There are " << charCount << " '" << userChar << "'s in '" << userStr << "'." << endl;
    }

    return 0;
}