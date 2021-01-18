#include <iostream>
#include <string>
#include <fstream>
#include <list>

#include "models/Student.hpp"

using namespace std;

int main()
{
    Student* student;

    student = new Student;
    student->setCode(1)->setName("Arash")->setAverage(20)->add();
    student->setCode(2)->setName("Arian")->setAverage(19)->add();
    student->setCode(3)->setName("Arman")->setAverage(18)->add();
    student->list();

    if (student->setName("Arash")->find(Field::Name))
    {
        student->debug();
    }
    else
    {
        cout << "NOT FOUND!" << endl;
    }

    if (student->setAverage(20)->find(Field::Average))
    {
        student->debug();
    }
    else
    {
        cout << "NOT FOUND!" << endl;
    }
    

    delete student;
    
}