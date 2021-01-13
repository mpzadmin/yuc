/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    string userStr;
    int words = 0;

    system("cls");

    cout << "Enter a sentence: ";
    getline(cin,userStr);

    // Trimming duplicate spaces
    for (
            // A boolean to determine if there's a duplicated space
            bool hasDuplicated =
                    userStr.find("  ") != string::npos
                    || userStr.find("\t\t") != string::npos
                    || userStr.find("\v\v") != string::npos
                    || userStr.find("\f\f") != string::npos;
            // Until there are duplicated spaces...
            hasDuplicated;
            // Check if there's still a duplicated space
            hasDuplicated =
                    userStr.find("  ") != string::npos
                    || userStr.find("\t\t") != string::npos
                    || userStr.find("\v\v") != string::npos
                    || userStr.find("\f\f") != string::npos
        )
    {
        // Turn two spaces into one space
        userStr = std::regex_replace(userStr, regex("  "), " ");
        userStr = std::regex_replace(userStr, regex("\t\t"), "\t");
        userStr = std::regex_replace(userStr, regex("\v\v"), "\v");
        userStr = std::regex_replace(userStr, regex("\f\f"), "\f");
    }

    // Trimming left spaces
    for (int i = 0; i < userStr.length(); ++i)
    {
        bool isCharWhiteSpace = userStr[i] == ' ' || userStr[i] == '\t' || userStr[i] == '\v' || userStr[i] == '\f';

        if (!isCharWhiteSpace)
        {
            int lastIndex = userStr.length() - 1;
            userStr = userStr.substr(i, lastIndex);

            break;
        }
    }

    // Trimming right spaces
    for (int i = userStr.length() - 1; i >= 0; --i)
    {
        bool isCharWhiteSpace = userStr[i] == ' ' || userStr[i] == '\t' || userStr[i] == '\v' || userStr[i] == '\f';

        if (!isCharWhiteSpace)
        {
            userStr = userStr.substr(0, i);

            break;
        }
    }

    // Count whitespaces
    for (int i = 0; i < userStr.length(); ++i)
    {
        bool isCharWhiteSpace = userStr[i] == ' ' || userStr[i] == '\t' || userStr[i] == '\v' || userStr[i] == '\f';

        if (isCharWhiteSpace)
        {
            words++;
        }
    }
    
    // Words = Whitespaces + 1
    words++;
    
    // Result
    cout << "This sentence includes " << words << " words." << endl;

    return 0;
}