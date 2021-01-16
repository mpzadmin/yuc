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

        bool error;
        string errorMessage;

    protected:

    public:
        Student();
        ~Student();

        Student* setCode(int code);
        Student* setName(string name);
        Student* setAverage(float average);

        int getCode();
        string getName();
        float getAverage();

        bool fail();
        string getError();
};

Student::Student()
{
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
    return this->error ? this->errorMessage : "";
}

Student* Student::setCode(int code)
{
    this->studentModel.code = code;
    return this;
}

Student* Student::setName(string name)
{
    this->studentModel.name = name;
    return this;
}

Student* Student::setAverage(float average)
{
    this->studentModel.average = average;
    return this;
}

int Student::getCode()
{
    return this->studentModel.code;
}

string Student::getName()
{
    return this->studentModel.name;
}

float Student::getAverage()
{
    return this->studentModel.average;
}