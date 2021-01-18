#include <iostream>
#include <string>
#include <list>
#include <fstream>

#include "models/student.hpp"

using namespace std;

int main()
{
    Student* student;
    
    student = new Student;
    student->setCode(1)->setName("Mahdi")->setAverage(17)->add();
    student->setCode(2)->setName("Matin")->setAverage(18)->add();
    student->setCode(3)->setName("Moeen")->setAverage(17.5)->add();
    student->setCode(4)->setName("Mobin")->setAverage(19)->add();
    student->list();
    
    delete student;
}