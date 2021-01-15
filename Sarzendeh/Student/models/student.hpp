#include <iostream>
#include <string>
#include <list>

using namespace std;

class StudentModel
{
    public:
        int code;
        string name;
        float average;
};

class Student
{
    private:
        StudentModel studentModel;
        list<StudentModel> students;

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