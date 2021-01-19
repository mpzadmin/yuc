#include <iostream>
#include "models/student.hpp"

using namespace std;

int main()
{
    Student* student;

    student = new Student;
    student->setCode(1)->setName("saeed")->setAverage(18)->add()->debug();
    student->setCode(2)->setName("saeed2")->setAverage(18)->add()->debug();
    student->setCode(3)->setName("saeed3")->setAverage(16)->add()->debug();
    student->setCode(4)->setName("saeed4")->setAverage(15)->add()->debug();
    student->list();

    student->setAverage(18)->filter(Field::Average)->list(true);

/*
    student->setCode(1)->remove()->list();
    if (student->setCode(1)->remove()->list()->fail())
    {
        cout << student->getError() << endl;
    }
*/
    /*if(student->fail())
        cout << student->getError() << endl;
    else
        cout << "Success" << endl;*/


    /*if(student->setName("saeed")->find(Field::Name))
        student->debug();
    else
        cout << "NOT FOUND!" << endl;*/
    
    delete student;
}