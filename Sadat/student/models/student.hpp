#include <iostream>
#include <list>

using namespace std;

class StudentModel
{
    public:
        string name;
        int code;
        float average;
};

class Student
{
    private:
        StudentModel studentModel;
        list<StudentModel> students;
        string errorMessage;
        bool error;
    protected:
    public:
        Student();
        ~Student();
        bool fail();
        string getError();
};

Student::Student()
{
    this->students.clear();
    this->error = false;
}

Student::~Student()
{

}

bool Student::fail()
{
    return this->error;
}

string Student::getError()
{
    return (this->error) ? this->errorMessage : "";
}