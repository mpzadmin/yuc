#include <iostream>
#include <string>
#include <list>
#include <fstream>

#include "models/student.hpp"

using namespace std;

int main()
{
    Student* student;
    
    student = new Student;
    student->setCode(1)->setName("Mahdi")->setAverage(17)->add();
    student->setCode(2)->setName("Matin")->setAverage(18)->add();
    student->setCode(3)->setName("Moeen")->setAverage(17.5)->add();
    student->setCode(4)->setName("Mobin")->setAverage(19)->add();
    student->list();

    if ( student->setCode(2)->setName("Matin")->setAverage(18)->add()->fail() )
    {
        cout << student->getError() << endl;
    }
    else
    {
        cout << "Successfully added data!" << endl;
    }

    if ( student->setCode(5)->setName("Alireza")->setAverage(16.5)->add()->fail() )
    {
        cout << student->getError() << endl;
    }
    else
    {
        cout << "Successfully added data!" << endl;
    }

    if ( student->setCode(10)->remove()->fail() )
    {
        cout << student->getError() << endl;
    }
    else
    {
        cout << "Student with code \"10\" successfully removed!" << endl;
    }
    

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    if (student->setCode(3)->find(Field::Code))
    {
        cout << "Student with code \"3\" was found!" << endl;
        student->debug();
    }
    else
    {
        cout << "Student with code \"3\" was NOT found!" << endl;
    }
    
    if (student->setName("Matin")->find(Field::Name))
    {
        cout << "Student with name \"Matin\" was found!" << endl;
        student->debug();
    }
    else
    {
        cout << "Student with name \"Matin\" was NOT found!" << endl;
    }
    
    if (student->setAverage(20)->find(Field::Average))
    {
        cout << "Student with average \"19\" was found!" << endl;
        student->debug();
    }
    else
    {
        cout << "Student with average \"19\" was NOT found!" << endl;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    delete student;
}