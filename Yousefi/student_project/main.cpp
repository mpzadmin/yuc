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
    
    Student* student;

    student = new Student;
    student->setcode(1)->setname("ali")->setaverage(14)->add();    
    student->setcode(2)->setname("omid")->setaverage(18)->add();
    student->list();    

    delete student;




    student->list();

    delete student;
}






