/*
 * Copyright © 2020 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 * Creation Date: 2020-12-26
 */

/** External Libraries **/
#include <iostream>
#include <string>
#include "console.hpp"

/** Namespaces **/
using namespace std;

/** Constants **/
struct Student
{
    size_t code;
    string firstName;
    string lastName;
    float grade;
};

/** Other Variables **/
Student* students;
size_t studentsCount;

/** Function Declarations **/
void getStudentsData();
void printStudentsData();
float getGradesAverage(Student* &s, size_t &studentsCount);

// Program's Entry Point
int main()
{
    float studentsAvg;

    clearConsole();

    studentsCount = askForInt("Enter the count of students: ");
    getStudentsData();

    printStudentsData();

    studentsAvg = getGradesAverage(students);
    printLine("The average grade of inserted students is: " + to_string(studentsAvg));

    pauseConsole();

    return 0;
}

// Gets students data from user
void getStudentsData()
{
    for (size_t i = 0; i < studentsCount; ++i)
    {
        students[i].code = askForInt("Enter student " + to_string(i) + "'s code: ");
        students[i].firstName = askForString("Enter student " + to_string(i) + "'s first name: ");
        students[i].lastName = askForString("Enter student " + to_string(i) + "'s last name: ");
        students[i].grade = askForFloat("Enter student " + to_string(i) + "'s grade: ");
    }
}

// Prints current student data
void printStudentsData()
{
    for (size_t i = 0; i < studentsCount; ++i)
    {
        printLine("Student " + to_string(students[i].code) + ": ");
        printLine("Name: " + students[i].firstName + "\tLast Name: " + students[i].lastName + "\tGrade: " + students[i].grade);
        printSeparatorLine('_', 2);
    }
}

// Calculates the average grade of students
float getGradesAverage()
{
    float sum = 0.0;

    for (size_t i = 0; i < studentsCount; ++i)
    {
        sum += s[i].grade;
    }

    return sum/studentsCount;
}
