#include <iostream>
#include <string>
#include <fstream>
#include <list>

#include "models/Student.hpp"

using namespace std;

int main()
{
    Student* student;

    system("cls");

    student = new Student;
    student->setCode(1)->setName("Arash Dehghani")->setAverage(20)->add();
    student->setCode(2)->setName("Arian Niakan")->setAverage(19)->add();
    student->setCode(3)->setName("Arman")->setAverage(18)->add();
    student->setCode(4)->setName("Arian Niakan")->setAverage(15.5)->add();
    student->setCode(5)->setName("Akbar Heidari")->setAverage(16)->add();
    student->setCode(6)->setName("Omid Ryazi")->setAverage(17)->add();
    student->setCode(7)->setName("Shahab Hoseini")->setAverage(19)->add();
    student->setCode(8)->setName("Hosein Dehghani")->setAverage(19.5)->add();
    cout << endl << "***************************************" << endl;
    
    // cout << student->first()->getName() << endl;
    student->setAverage(10)->filter(Field::Average)->first(true)->debug();
    // cout << endl << "------------------------" << endl;
    // student->sort(Field::Average, SortMode::Desc)->limit(1)->list();
    // cout << endl << "------------------------" << endl;

   /* cout << endl << "------------------------" << endl;
    student->sort(Field::Average)->limit(1)->list();
    cout << endl << "------------------------" << endl;
*/

    
    /*
    cout << endl << "------------------------" << endl;
    student->setAverage(20)->filter(Field::Average)->sort(Field::Name)->limit(1)->list(true);
    cout << endl << "------------------------" << endl;
    student->setName("Arash")->filter(Field::Name)->list(true);
    */   
    /*
    student->setCode(2)->remove()->list();
    if (student->setCode(2)->remove()->fail())
    {
        cout << student->getError() << endl;
    }
    */

    /*
    if ( !student->setCode(1)->setName("Arash")->setAverage(19->add()->fail()))
    {
        cout << "Success" << endl;
    }
    else
    {
        cout << student->getError() << endl;
    }
    
    

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
    }*/
    

    delete student;
    
}