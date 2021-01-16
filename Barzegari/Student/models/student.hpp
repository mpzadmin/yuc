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
        bool fail();
        string getError();

        Student* setCode(int code);
        int getCode();
        Student* setName(string name);
        string getName();
        Student* setAverage(float avrage);
        float getAverage();
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
    return error;
}

string Student::getError()
{
    return this->error ? this->errorMessage : "";
}

Student* Student::setCode(int code)
{
    this->studentModel.code = code;
}

int Student::getCode()
{
    return this->studentModel.code;
}

string Student::setName(string name)
{
    this->studentModel.name = name;
}

Student* Student::getName()
{
    this->studentModel.name;
}

float Student::setAverage(float avrage)
{
    this->studentModel.average = avrage;
}

Student* Student::getAverage()
{
    return this->studentModel.average;
}