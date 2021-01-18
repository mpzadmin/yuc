#include <iostream>
#include "models/student.hpp"

using namespace std;

int main()
{
    Student* student;

    student = new Student;
    student->setCode(1)->setName("saeed")->setAverage(18)->add()->debug();
    student->list();

    if(student->fail())
        cout << student->getError() << endl;
    else
        cout << "Success" << endl;


    /*if(student->setName("saeed")->find(Field::Name))
        student->debug();
    else
        cout << "NOT FOUND!" << endl;*/
    
    delete student;
}