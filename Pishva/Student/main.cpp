#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "models/student.hpp"

using namespace std;

int main ()
{
    Student* student;

    student = new Student;
    
    student->setCode(1)->setName("Mohammad")->setAverage(19)->add();
    student->setCode(2)->setName("Amir")->setAverage(18)->add();
    student->list();

    delete student;
    return 0;
}