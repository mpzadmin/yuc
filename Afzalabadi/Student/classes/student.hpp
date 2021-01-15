#include<iostream>
#include<fstream>
#include<string>
#include<list>

using namespace std;

class StudentModel
{
     public:
         int code;
         string name;
         float avarage;

};

class Student
{
     private:
         StudentModel studentModel;
         list <StudentModel> students;

         bool error;

     public:
         Student();
         ~Student();


};

Student::Student()
{
     this-> students.clear();
     this-> error = false;
}

Student:: ~Student()
{
    
}
