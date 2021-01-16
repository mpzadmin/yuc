/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/**
 * @file classroom_management.cpp
 * @brief A program with the purpose of helping teachers manage their class easier.
 */

/** External Libraries **/
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
Student* studentsPtr;
size_t studentsCount;

/** Function Declarations **/
Student getStudent(const size_t &index);
void getStudentsData();
void printStudentsData();
float getGradesAverage();

// Program's Entry Point
int main()
{
    float studentsAvg;

    clearConsole();

    studentsCount = askForInt("Enter the count of students: ");
    //cin >> studentsCount;
    getStudentsData();

    printStudentsData();

    studentsAvg = getGradesAverage();
    printLine("The average grade of inserted students is: " + to_string(studentsAvg));

    pauseConsole();

    return 0;
}

Student getStudent(const size_t &index)
{
    return *(studentsPtr + index);
}

// Gets students data from user
void getStudentsData()
{
    //Student s;

    for (size_t i = 0; i < studentsCount; ++i)
    {
        //s = getStudent(i);

        cin >> (*(studentsPtr + i)).code; //= askForInt("Enter student " + to_string(i+1) + "'s code: ");
//        s.firstName = askForString("Enter student " + to_string(i+1) + "'s first name: ");
//        s.lastName = askForString("Enter student " + to_string(i+1) + "'s last name: ");
//        s.grade = askForFloat("Enter student " + to_string(i+1) + "'s grade: ");
//    students[i].code = i*2;
//    students[i].firstName = "A" + to_string(i*2);
//    students[i].lastName = "B" + to_string(i*2);
//    students[i].grade = 2.5;

    }
}

// Prints current student data
void printStudentsData()
{
    Student s;

    for (size_t i = 0; i < studentsCount; ++i)
    {
        s = getStudent(i);

        printLine("Student " + to_string(s.code) + ": ");
        printLine("Name: " + s.firstName + "\tLast Name: " + s.lastName + "\tGrade: " + to_string(s.grade));
        printSeparatorLine('_', 2);
    }
}

// Calculates the average grade of students
float getGradesAverage()
{
    float sum = 0.0;

    for (size_t i = 0; i < studentsCount; ++i)
    {
        sum += getStudent(i).grade;
    }

    return sum/studentsCount;
}
