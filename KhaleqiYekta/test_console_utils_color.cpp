/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file test_console_utils_color.cpp
 * @brief Test console coloring using console_utils.hpp.
 */

/** External Libraries **/
#include "console_utils.hpp"

/** Namespaces **/
using namespace c;

// Program's Entry Point
int main() {
    clear();

    println("** Console utils library by Ali Khaleqi Yekta **", B_YELLOW);
    println("\nForeground colors test: \n");

    print(" Black \t\t",BLACK,B_WHITE);
    print(" Red \t\t",RED);
    print(" Green \t\t",GREEN);
    print(" Yellow \t",YELLOW);
    print(" Blue \n",BLUE);
    print(" Magenta \t",MAGENTA);
    print(" Cyan \t\t",CYAN);
    print(" White \t\t",WHITE);
    print(" B Black \t",B_BLACK);
    print(" B Red \n",B_RED);
    print(" B Green \t",B_GREEN);
    print(" B Yellow \t",B_YELLOW);
    print(" B Blue \t",B_BLUE);
    print(" B Magenta \t",B_MAGENTA);
    print(" B Cyan \n",B_CYAN);
    print(" B White \t",B_WHITE);

    println("\n\nBackground colors test: \n");

    print(" Black \t\t", B_WHITE, BLACK);
    print(" Red \t\t", B_WHITE, RED);
    print(" Green \t\t", B_WHITE, GREEN);
    print(" Yellow \t", B_WHITE, YELLOW);
    print(" Blue \n", B_WHITE, BLUE);
    print(" Magenta \t", B_WHITE, MAGENTA);
    print(" Cyan \t\t", B_WHITE, CYAN);
    print(" White \t\t", BLACK, WHITE);
    print(" B Black \t", B_WHITE, B_BLACK);
    print(" B Red \n", B_WHITE, B_RED);
    print(" B Green \t", BLACK, B_GREEN);
    print(" B Yellow \t", BLACK, B_YELLOW);
    print(" B Blue \t", B_WHITE, B_BLUE);
    print(" B Magenta \t", B_WHITE, B_MAGENTA);
    print(" B Cyan \n", BLACK, B_CYAN);
    print(" B White \t", BLACK, B_WHITE);

    println();
    println();

    pause();
    return 0;
}
