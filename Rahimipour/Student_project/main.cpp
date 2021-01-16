#include <iostream>
#include <string>
#include <fstream>
#include <list>

#include "models/student.hpp"

using namespace std;

int main()
{
    Student* student;

    student = new Student;

    student->setCode(1)->setName("Ahad")->setAverage(19.5)->debug();
    student->setCode(1)->setName("Ahad")->setAverage(19.5)->debug();
    

    delete student;
}