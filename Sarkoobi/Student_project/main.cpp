#include <iostream>
#include <list>
#include <string>

#include "models/student.hpp"
using namespace std;

int main() 
{
    Student* student;

    student = new Student;
    student->setCode(1)->setName("Mojtaba")->setAverage(19)->add();
    student->setCode(2)->setName("Asgar")->setAverage(15)->add();
    student->list();
    student->setCode(2)->remove()->list();
    if ( student->setCode(2)->remove()->list())
    {
        cout << student->getError() << endl;
    }
    
    /*
    if (!student->setCode(1)->setName("Mojtaba")->setAverage(19)->add()->fail())
    {
        cout << "Success" << endl
    }
    else
    {
        cout << student->getError() << endl;
    }
    
    if (student->setName("jafar")->find(Field::Name))
    {
        student->debug();
    }
    else
    {
        cout << "NOT FOUND!" << endl;
    }
    */
    delete student;
    return 0;
}
