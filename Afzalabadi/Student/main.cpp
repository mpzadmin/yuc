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
    student->list();    

    delete student;

}