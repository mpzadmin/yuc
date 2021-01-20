#include <iostream>
#include <list>
#include <string>

#include "models/student.hpp"
using namespace std;

int main() 
{
    Student* student;
    system("cls");
    student = new Student;
    student->setCode(1)->setName("Mojtaba")->setAverage(19)->add();
    student->setCode(2)->setName("Asgar kobrayazdah")->setAverage(15)->add();
    student->setCode(3)->setName("Narges bano")->setAverage(20)->add();
    student->setCode(4)->setName("sara daraiee")->setAverage(20)->add();
    student->setCode(5)->setName("Akbar Gigmanesh")->setAverage(18.5)->add();
    cout << endl << "----------------------------------------------------------------" << endl;
    //student->sort(Field::Average, SortMode::Desc)->list();
    //student->sort(Field::Name)->list();
    student->setAverage(20)->filter(Field::Average)->sort(Field::Name)->list(true);
    cout << endl << "----------------------------------------------------------------" << endl;

    /*
    student->setAverage(20)->filter(Field::Average)->list(true);
    cout << endl << "----------------------------------------------------------------" << endl;
    student->setName("Mojtaba")->filter(Field::Name)->list(true);
    
    student->setCode(2)->remove()->list();
    if ( student->setCode(2)->remove()->list())
    {
        cout << student->getError() << endl;
    }
    
    if (!student->setCode(1)->setName("Mojtaba")->setAverage(19)->add()->fail())
    {
        cout << "Success" << endl
    }
    else
    {
        cout << student->getError() << endl;
    }
    
    if (student->setName("jafar")->find(Field::Name))
    {
        student->debug();
    }
    else
    {
        cout << "NOT FOUND!" << endl;
    }

    */
    delete student;
}
