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
        StudentModel studentmodel;
        list<StudentModel> students;

        bool error;

        string errorMessage;
    protected:

    public:
        Student();
        ~Student();
        bool fail();
        string getError;
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
    return this->error ? this->errorMessage : " ";
}