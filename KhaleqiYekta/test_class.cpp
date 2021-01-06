/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file test_class.cpp
 * @brief Learning classes.
 */

/** External Libraries **/
#include <iostream>
#include <string>
#include "console.hpp"

/** Namespaces **/
using namespace std;

class Car
{
    public:
        string brand;
        string model;
        int year;

        Car();
        Car(string b, string m, int y);
        ~Car();
};

Car::Car()
{
    printLine("Car Initialization!");
}

Car::Car(string b, string m, int y)
{
    brand = b;
    model = m;
    year = y;

    printLine("Car Initialization!");

    cout << brand << " " << model << " " << year << endl;
}

Car::~Car()
{
    cout << "Car Destruction!" << endl;
}

// Program's Entry Point
int main() {
    clearConsole();

    Car bmw;
    Car saipa("Pride","70",1370);

    pauseConsole();
    return 0;
}
