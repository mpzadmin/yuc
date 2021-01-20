#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "model/student.hpp"
using namespace std;
 
int main()
{
    Student* student;
    student = new Student;
    student->setCode(1)->setName("dani")->setAverage(10)->add();
    student->setCode(2)->setName("do")->setAverage(10)->add();
    student->setCode(3)->setName("ali")->setAverage(20)->add();
    student->setCode(4)->setName("hasani")->setAverage(20)->add();
    student->sort(Field::Name)->list();
    student->sort(Field::Average)->list();
   /* if(student->setName("ali")->find(Field::Name))
    {
      student->debug();
    }
    else
    {
      cout << "Not found!" << endl;
    }
    if( !student->setCode(1)->setName("dani")->setAverage(10)->add()->fail())
    {
      cout << "success" << endl;
    }
    else
    {
      {
        cout << student->getError() <<  endl;
      }
    }*/
    
    delete student;
} 
