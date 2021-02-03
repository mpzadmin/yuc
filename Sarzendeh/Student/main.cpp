#include <iostream>
#include <string>
#include <list>
#include "models/student.hpp"

using namespace std;

int main()
{
    Student* student;

    student = new Student;

    student
        ->setCode(1)
        ->setName("Ehsan")
        ->setAverage(19)
        ->add();
    student
        ->setCode(2)
        ->setName("Reza")
        ->setAverage(18)
        ->add();
    student
        ->setCode(3)
        ->setName("Ali")
        ->setAverage(18)
        ->add();

    student->list();

    student->setAverage(18)->filter(Field::Average)->sort(Field::Code, SortMode::Desc)->list(true);

    // student->setCode(3)->setName("Ali")->setAverage(17)->add();
    // if (!student->fail())
    // {
    //     cout << "Success" << endl;
    // }
    // else
    // {
    //     cout << student->getError() << endl;
    // }

    // if (student->setName("Reza")->find(Field::Name))
    // {
    //     student->debug();
    // }
    // else
    // {
    //     cout << "NOT FOUND" << endl;
    // }
        
    delete student;
}