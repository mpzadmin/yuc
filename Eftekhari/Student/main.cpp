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
    student->setCode(1)->setName("Ali")->setAverage(19)->add();    
    student->setCode(2)->setName("Reza")->setAverage(18)->add();
    student->setCode(3)->setName("Amir")->setAverage(18.5)->add();
    student->list();    

    delete student;
}