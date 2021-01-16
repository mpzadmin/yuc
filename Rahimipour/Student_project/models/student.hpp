#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

class StudentModel
{
    public:
        int code;
        string name;
        float average;
};

class Student // main class
{
    private:
        StudentModel studentModel;
        list<StudentModel> students;

        bool error;
    protected:
    public:
        Student();
        ~Student();
};

Student::Student()
{
    this->students.clear();
    this->error = false;

}

Student::~Student()
{
    
}