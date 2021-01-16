#include <iostream>
#include <list>
#include <fstream>
#include "models/student.hpp"

using namespace std;

int main()
{
    Student* student;
    student = new Student;

    student->setCode(1)->setName("ali")->setAverage(15.8)->debug();

    delete student;
}