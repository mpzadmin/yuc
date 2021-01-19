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
    student->setCode(3)->setName("Taha")->setAverage(19)->add();// add data to list.
    student->setCode(4)->setName("Reza")->setAverage(18)->add();
    student->setCode(5)->setName("Mohammad")->setAverage(10)->add();
    student->setCode(6)->setName("Yasin")->setAverage(12.5)->add();
    student->setCode(7)->setName("Javad")->setAverage(20)->add();
    student->list2();
    student->setAverage(20)->filter(Field::Average)->list2(true);

    student->setCode(2)->remove()->list2();
    if ( student->setCode(2)->remove()->fail() )
    {
        cout << student->getError() << endl;
    }
    
    /*
    if ( !student->setCode(10)->setName("Ali")->setAverage(16)->add()->fail() ) 
    {
        cout << "Success" << endl;
    }

    else
    {
        cout << student->getError() << endl;
    }
    //student->setCode(2)->setName("Ali")->setAverage(16)->debug();// won't be showed, because we add don't repeat code.
    //student->list2();
    /**
     *! Why it doesn't work???????
     */
    /*
    if ( student->setName("Ahmad")->find(Field::Name) ) // ... == true
    {
        student->debug();
    }

    else
    {
        cout << "NOT FOUND!" << endl;
    }

    if ( student->setAverage(5)->find(Field::Average) )
    {
        student->debug();
    }

    else
    {
        cout << "NOT FOUND!" << endl;
    }
    */
    
    
    delete student;
}