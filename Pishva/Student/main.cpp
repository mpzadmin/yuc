#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "models/student.hpp"

using namespace std;

int main ()
{
    Student* student;

    student = new Student;
    
    student->setCode(1)->setName("Mohammad")->setAverage(19)->add();
    student->setCode(2)->setName("Amir")->setAverage(18)->add();
    student->setCode(1)->setName("Mohammad")->setAverage(19)->add();
    student->setCode(3)->setName("Mohammad")->setAverage(19)->add();
    student->list();

    if (student->setName("Ali")->find(Field::Name))
        student->debug();
    else
        cout << "NOT FOUND!" << endl;

    if (student->setName("Mohammad")->find(Field::Name))
        student->debug();
    else
        cout << "NOT FOUND!" << endl;

    delete student;
    return 0;
}