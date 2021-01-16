#include <iostream>
#include <string>
#include <fstream>
#include <list>

#include "models/Student.hpp"

using namespace std;

int main()
{
    Student* student;

    student = new Student;
    student->setCode(1)->setName("Arash")->setAverage(20)->debug();
    student->setCode(1)->setName("Arash")->setAverage(20)->debug();

    delete student;
    
}