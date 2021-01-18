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
    student->setCode(1)->setName("dani")->setAverage(10)->add();
    student->list();
    if(student->setName("ali")->find(Field::Name))
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
    }
    
    delete student;
} 