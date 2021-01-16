#include <iostream>
#include <string>
#include <list>
#include "models/student.hpp"

using namespace std;

int main()
{
    Student* student;

    student = new Student;

    student
        ->setCode(1)
        ->setName("Ehsan")
        ->setAverage(19)
        ->debug();
    student
        ->setCode(2)
        ->setName("Reza")
        ->setAverage(18)
        ->debug();

    student->list();
        
    delete student;
}