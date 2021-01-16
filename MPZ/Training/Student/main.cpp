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
    student->setCode(1)->setName("Masoud")->setAverage(17)->add();    
    student->setCode(2)->setName("Omid")->setAverage(20)->add();
    student->setCode(3)->setName("Arman")->setAverage(18.5)->add();
    student->list();    

    delete student;
}