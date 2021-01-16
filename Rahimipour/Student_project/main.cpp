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
    student->setCode(2)->setName("Ali")->setAverage(16)->debug();
    student->setCode(3)->setName("Taha")->setAverage(19.75)->add();
    student->list();

    delete student;
}