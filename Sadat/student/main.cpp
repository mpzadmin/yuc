#include <iostream>
#include <list>
#include <fstream>
#include "models/student.hpp"

using namespace std;

int main()
{
    Student* student;
    student = new Student;

    student->setCode(1)->setName("ali")->setAverage(15.8);
    if (!student->find(Field::Code)) student->add();
    student->setCode(1)->setName("reza")->setAverage(18.5);
    if (!student->find(Field::Code)) student->add();
    student->setCode(2)->setName("pouya")->setAverage(18);
    if (!student->find(Field::Code)) student->add();
    student->setCode(3)->setName("mohsen")->setAverage(19);
    if (!student->find(Field::Code)) student->add();
    student->list();

    if (student->setName("pouya")->find(Field::Name))
    {
        student->debug();
    }
    else
    {
        SetConsoleTextAttribute(console, 2);
        cout << "NOT FOUND!" << endl;
        SetConsoleTextAttribute(console, 7);
    }
    

    delete student;
}