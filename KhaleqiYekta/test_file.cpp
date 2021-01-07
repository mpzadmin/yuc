/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file test_file.cpp
 * @brief Test working with files.
 */

/** External Libraries **/
#include <iostream>
#include <string>
#include <fstream>
#include "console.hpp"

/** Namespaces **/
using namespace std;

// Program's Entry Point
int main() {
    fstream file;

    clearConsole();

    file.open("test.txt", ios::out);
    if (!file.is_open())
    {
        printLine("Error in opening the text file!");
    }

    file << "Hello World!" << endl;
    file << "This program is written in C++; ";
    file << "however, I wish it was written in Kotlin instead!" << endl;

    file.close();

    /** End of the program **/
    pauseConsole();
    return 0;
}
