#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "models/student.hpp"

using namespace std;

int main ()
{
    Student* student;

    system("cls");

    student = new Student;
    student->setCode(1)->setName("Mohammad")->setAverage(19)->add();
    student->setCode(2)->setName("Amir")->setAverage(18)->add();
   // student->setCode(1)->setName("Mohammad")->setAverage(19)->add();
    student->setCode(3)->setName("MohammadAli")->setAverage(19)->add();
    student->setCode(6)->setName("AmirReza")->setAverage(19)->add();
    student->setCode(4)->setName("Ali")->setAverage(17)->add();
    student->setCode(5)->setName("Reza")->setAverage(15)->add();
    student->list();
    cout << "---------------------------------------------------" << endl;
    //student->sort(Field::Average, SortMode::Desc)->list();
    //student->sort(Field::Name, SortMode::Desc)->list();
    student->setAverage(19)->filter(Field::Average)->sort(Field::Name)->limit(1)->list(true);
    cout << "**************************************************" << endl;

    /*
    cout << "---------------------------------------------------" << endl;
    student->setAverage(19)->filter(Field::Average)->list(true);*/

    /*
    student->setCode(2)->remove()->list();
    if (student->setCode(2)->remove()->fail())
        cout << student->getError() << endl;*/
    
    /*
    student->setCode(1)->setName("Mohammad")->setAverage(18)->add();
    if ( !student->fail() )
        cout << "Success" << endl;
    else
        cout << student->getError() << endl;*/ 
    /*
    if (student->setName("Ali")->find(Field::Name))
        student->debug();
    else
        cout << "NOT FOUND!" << endl;

    if (student->setName("Mohammad")->find(Field::Name))
        student->debug();
    else
        cout << "NOT FOUND!" << endl;*/

    delete student;
    return 0;
}