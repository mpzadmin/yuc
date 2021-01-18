#include <iostream>
#include "models/student.hpp"

using namespace std;

int main()
{
    Student* student;

    student = new Student;
    student->setCode(1)->setName("saeed")->setAverage(18)->debug();
    student->list();

    if(student->setName("saeed")->find(Field::Name))
        student->debug();
    else
        cout << "NOT FOUND!" << endl;
    
    delete student;
}