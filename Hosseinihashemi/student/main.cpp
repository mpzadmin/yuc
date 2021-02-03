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
    student->setCode(1)->setName("Masoud PourZahmatkesh")->setAverage(17)->add();
    student->setCode(2)->setName("Omid")->setAverage(20)->add();
    student->setCode(3)->setName("Arman PourZahmatkesh")->setAverage(18.5)->add();
    student->setCode(4)->setName("Omid")->setAverage(19)->add();
    student->setCode(5)->setName("Mina Hoseini")->setAverage(20)->add();
    student->setCode(6)->setName("Maryam Zareh")->setAverage(10)->add();
    student->setCode(7)->setName("Reza Soleimani")->setAverage(20)->add();
    student->setCode(8)->setName("Hamid Ebrahimi")->setAverage(10)->add();
    cout << endl << "*****************************************************" << endl;
    //student->sort(Field::Average, SortMode::Desc)->list();
    //student->sort(Field::Name)->list();
    //student->setAverage(20)->filter(Field::Average)->sort(Field::Name)->limit(2)->list(true);
    //cout << endl << "*****************************************************" << endl;

    cout << endl << "*****************************************************" << endl;
    student->sort(Field::Average, SortMode::Desc)->limit(1)->list();
    cout << endl << "*****************************************************" << endl;

    cout << endl << "*****************************************************" << endl;
    student->sort(Field::Average)->limit(1)->list();
    cout << endl << "*****************************************************" << endl;


    /*
    cout << endl << "-------------------------------------------------------------" << endl;
    student->setAverage(20)->filter(Field::Average)->list(true);
    cout << endl << "-------------------------------------------------------------" << endl;
    student->setName("Omid")->filter(Field::Name)->list(true);
    */


    /*
    student->setCode(2)->remove()->list();
    if (student->setCode(2)->remove()->fail())
    {
        cout << student->getError() << endl;
    }
    */
    
    /*
    if ( !student->setCode(10)->setName("Masoud")->setAverage(17)->add()->fail() )
    {
        cout << "Success" << endl;
    } 
    else 
    {
        cout << student->getError() << endl;
    }

    if ( student->setName("Omid")->find(Field::Name) )
    {
        student->debug();
    } 
    else
    {
        cout << "NOT FOUND!" << endl;
    }

    if ( student->setAverage(17)->find(Field::Average) )
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