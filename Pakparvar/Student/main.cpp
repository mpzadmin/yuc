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
    student->setCode(2)->remove()->list();

    if (student->setCode(2)->remove()->fail())
    {
        cout << student->getError() << endl;
    }

    if(student->setCode(10)->setName("ali")->setAverage(20)->add()->fail())
    {
        cout << "Success" << endl;
    }
    else
    {
        cout << student->getError() << endl;
    }
    

    if(student->setName("Omid")->find(Field::Name))
    {
        student->debug();
    }
    else
    {
        cout << "NOT FOUND";
    }

    if (student->setAverage(16)->find(Field::Average))
    {
        student->debug();
    }
    else
    {
        cout << "NOT FOUND!";
    }
    
    delete student;
}