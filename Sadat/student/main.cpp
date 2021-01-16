#include <iostream>
#include <list>
#include <fstream>
#include "models/student.hpp"

using namespace std;

int main()
{
    Student* student;
    student = new Student;

    student->setCode(1)->setName("ali")->setAverage(15.8)->add();
    student->setCode(2)->setName("reza")->setAverage(18.5)->add();
    student->setCode(3)->setName("pouya")->setAverage(18)->add();
    student->setCode(4)->setName("mohsen")->setAverage(19)->add();
    student->list();

    delete student;
}