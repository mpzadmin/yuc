#include<iostream>
#include<string>
#include"classes/student.hpp"

using namespace std;

int main()
{
   
    Student* student;

    student = new Student;
    student->setCode(1)->setName("ali")->setAvarage(20)->add();    
    student->setCode(2)->setName("reza")->setAvarage(19)->add();
    student->setCode(3)->setName("hossien")->setAvarage(10)->add();
    student->setCode(4)->setName("hossien")->setAvarage(15)->add();
    student->setCode(5)->setName("Mohammad")->setAvarage(17)->add();
    student->setCode(6)->setName("Arman")->setAvarage(20)->add();
    student->setCode(7)->setName("Omid")->setAvarage(20)->add();
    //student->list(); 

    
    cout << endl << "*****************************************************" << endl;
    student->sort(Field::Average, SortMode::Desc)->limit(1)->list();
    cout << endl << "*****************************************************" << endl;

    cout << endl << "*****************************************************" << endl;
    student->sort(Field::Average)->limit(2)->list();
    cout << endl << "*****************************************************" << endl;


/*
    cout << "\n" ;
    cout << "*********************" <<endl;
    student -> setAvarage(20)-> filter(Field :: Average)-> list(true);
    cout << "*********************" <<endl;
    student -> setName("ali")-> filter(Field :: Name)-> list(true);
*/

   /*  student->setCode(2)->remove()->list();
    if (student->setCode(2)->remove()->fail())
    {
        cout << student->getError() << endl;
    }

    
    
    if ( !student->setCode(10)->setName("ali")->setAverage(20)->add()->fail() )
    {
        cout << "Success" << endl;
    } 
    else 
    {
        cout << student->getError() << endl;
    }

    if ( student->setName("reza")->find(Field::Name) )
    {
        student->debug();
    } 
    else
    {
        cout << "NOT FOUND!" << endl;
    }

    if ( student->setAverage(18)->find(Field::Average) )
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