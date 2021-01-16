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
    string txt;
    cout << "Type something: ";
    getline(cin, txt);
    for(int i = txt.length(); i >= 0; i--)
    {
        cout << txt[i] << endl;
    }
}