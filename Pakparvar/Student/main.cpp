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
    student->setCode(1)->setName("Hossein")->setAverage(19)->add();
    student->setCode(2)->setName("Ali")->setAverage(20)->add();
    student->list();
    if(student->setName("Omid")->find(Field::Name))
    {
        student->debug();
    }
    else
    {
        cout << "NOT FOUND";
    }
    


    delete student;
}