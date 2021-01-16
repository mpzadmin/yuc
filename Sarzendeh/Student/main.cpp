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
        ->setAverage(17)
        ->add();

    student->list();
        
    delete student;
}