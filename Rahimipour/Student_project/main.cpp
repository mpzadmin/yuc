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

    student->setCode(1)->setName("Ahad")->setAverage(19.5)->add();// print data
    student->setCode(2)->setName("Ali")->setAverage(16)->add();
    student->setCode(3)->setName("Taha")->setAverage(19.75)->add();// add data to list.
    //student->list();

    if ( student->setName("Bay")->find(Field::Name) ) // ... == true
    {
        student->debug();
    }

    else
    {
        cout << "NOT FOUND!" << endl;
    }
    
    delete student;
}