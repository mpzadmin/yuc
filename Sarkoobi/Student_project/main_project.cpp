#include <iostream>
#include <list>
#include <string>

#include "models/student.hpp"
using namespace std;

int main() 
{
    Student* Student;

    Student = new Student;
    Student->setCode(1)->setName("Mojtaba")->setAverage(19)->add();
    Student->setCode(1)->setName("Asgar")->setAverage(15)->add();
    Student->list();
    delete student
}
