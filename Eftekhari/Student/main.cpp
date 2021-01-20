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
    student->setCode(1)->setName("Alireza Eftekhari")->setAverage(18.95)->add();
    student->setCode(2)->setName("Zahra Eftekhari")->setAverage(19.86)->add();
    student->setCode(3)->setName("Amir Eftekhari")->setAverage(18)->add();
    student->setCode(4)->setName("Milad Mohammadshahi")->setAverage(15)->add();
    student->setCode(5)->setName("Hamidreza Eftekhari")->setAverage(14.5)->add();
    cout << endl << "*****************************************************" << endl;
    student->sort(Field::Average, SortMode::Desc)->limit(1)->list();
    cout << endl << "*****************************************************" << endl;
    student->sort(Field::Average)->limit(1)->list();
    cout << endl << "*****************************************************" << endl;
    delete student;
}