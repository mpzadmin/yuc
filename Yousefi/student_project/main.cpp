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
    //student->setcode(1)->setname("habib")->setAverage(18)->debug();
    
    student->list();

    delete student;
}






