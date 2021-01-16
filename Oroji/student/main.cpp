#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "model/student.hpp"
using namespace std;
 
int main()
{
    Student* student;
    student = new Student;
    student->setCode(1)->setName("dani")->setAverage(10)->debug();
      student->setCode(1)->setName("dani")->setAverage(10)->add();
    student->list();
    delete student;
} 