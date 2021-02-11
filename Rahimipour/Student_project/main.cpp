#include <iostream>
#include <string>
#include <fstream>
#include <list>

#include "models/student.hpp"

using namespace std;

int main()
{
    Student* student;

    system("cls");

    student = new Student;

    student->setCode(1)->setName("Ahad")->setAverage(19.5)->add();// print data
    student->setCode(2)->setName("Ali")->setAverage(16)->add();
    student->setCode(3)->setName("Taha")->setAverage(19)->add();// add data to list.
    student->setCode(4)->setName("Reza")->setAverage(18)->add();
    student->setCode(5)->setName("Mohammad")->setAverage(10)->add();
    student->setCode(6)->setName("Yasin")->setAverage(12.5)->add();
    student->setCode(7)->setName("Javad")->setAverage(18)->add();
    //student->sort(Field::Average)->list2();
    //student->sort(Field::Average, SortMode::Desc)->list2();
    //student->sort(Field::Name)->list2();
    
    //cout << student->first()->getName() << endl;
    student->setAverage(18)->filter(Field::Average)->first(true)->getName();
    
    
    //cout << "*/*/*/*/*/*/*/*/*/*/*" << endl;
    //student->setAverage(18)->filter(Field::Average)->sort(Field::Name)->limit(1)->list2(true);
    //student->list2();
    //cout << endl << "*/*/*/*/*/*/*/*/*/*" << endl;
    
    //cout << "*/*/*/**/" << endl;
    //student->sort(Field::Average)->limit(2)->list2();
    
    
    //student->setAverage(20)->filter(Field::Average)->list2(true);
    /*
    student->setCode(2)->remove()->list2();
    if ( student->setCode(2)->remove()->fail() )
    {
        cout << student->getError() << endl;
    }
    */
    
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