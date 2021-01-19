/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file main.cpp
 * @brief Student management project.
 */

/** External Libraries **/
#include <iostream>
#include "libs/console_utils.hpp"
#include "models/student.hpp"

/** Namespaces **/
using namespace std;

/** Typedefs **/
/** Constants **/
/** Other Variables **/
/** Function Declarations **/

/**
 * Program's Entry Point
 */
int main()
{
    c::clear();
    /** Start of the program **/

    Student* student;

    student = new Student;
    student->setCode(1)->setName("Ali")->setAverage(20)->add();
    student->setCode(2)->setName("Mehdi")->setAverage(2.5)->add();
    student->setCode(3)->setName("Reza")->setAverage(19.5)->add();
    student->setCode(4)->setName("Reyhaneh")->setAverage(20)->add();


    if (!student->setCode(5)->setName("Bita")->setAverage(8.75)->add()->fail())
    {
        cout << "Student has been successfully added!" << endl;
    }
    else
    {
        cout << student->getError() << endl;
    }

    c::printlnSeparator('*',40);
    student->setAverage(20)->filter(Field::Average)->list(true);
    c::printlnSeparator('*',40);
    student->setName("Ali")->filter(Field::Name)->list(true);
    c::printlnSeparator('*',40);


    delete student;

    /** End of the program **/
    c::pause();
    return 0;
}
