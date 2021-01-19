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
    student->setCode(1)->setName("Alireza")->setAverage(16)->add();
    student->setCode(2)->setName("Amir")->setAverage(18)->add();
    student->setCode(3)->setName("Sina")->setAverage(19.75)->add();
    student->list();
    student->setCode(1)->remove()->list();
    if (student->setCode(1)->remove()->fail())
    {
        cout << student->getError() << endl;
    }


    delete student;
}