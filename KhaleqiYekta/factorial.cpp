/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file factorial.cpp
 * @brief A program which calculates the factorial of a number.
 */

/** External Libraries **/
#include <string>
#include "console.hpp"

/** Namespaces **/
using namespace std;

/** Function Declarations **/
size_t factorial(const size_t &number);

// Program's Entry Point
int main()
{
    clearConsole();

    // Test the factorial function with some numbers
    for (size_t i = 0; i <= 8; ++i)
    {
        printLine(to_string(i) + "! = " + to_string(factorial(i)));
    }

    /** End of the program **/
    pauseConsole();
    return 0;
}

// Calculates the factorial of a number
size_t factorial(const size_t &number)
{
    if (number < 1)
        return 1;

    return (number > 1) ? number * factorial(number - 1) : number;
}
