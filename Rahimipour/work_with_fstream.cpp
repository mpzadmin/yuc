/**
 * Copyright (c) 2021-2022
 * ahadrahimipour@gmail.com
 * 
 * @file fstream.cpp
 * Just a quick show to review comment and working on fstream
 * 
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
    
int main()
    
{
    fstream injaneb;
    string str;
    injaneb.open("fstream.txt", ios::out);

    injaneb << "Hello" << endl;
    injaneb << "It's Injaneb," << endl;
    injaneb << "Welcome!" << endl;

    injaneb.close();

    injaneb.open("fstream.txt", ios::in);
    
    while (! injaneb.eof())
    {
        getline(injaneb, str);
        cout << str << endl;
    }
    
    injaneb.close();
}


