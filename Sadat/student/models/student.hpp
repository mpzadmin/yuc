#include <iostream>
#include <list>

using namespace std;

class StudentModel
{
    public:
        string name;
        float average;
};

class Student
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

}

Student::~Student()
{

}