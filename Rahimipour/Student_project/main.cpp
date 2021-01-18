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
    student->setCode(2)->setName("Ali")->setAverage(16)->add();// won't be showed, because we add don't repeat code.
    //student->list();
    /**
     *! Why it doesn't work???????
     */
    if ( student->setName("Bay")->find(Field::Name) ) // ... == true
    {
        student->debug();
    }

    else
    {
        cout << "NOT FOUND!" << endl;
    }

    if ( student->setAverage(16)->find(Field::Average) )
    {
        student->debug();
    }

    else
    {
        cout << "NOT FOUND!" << endl;
    }
    
    
    delete student;
}