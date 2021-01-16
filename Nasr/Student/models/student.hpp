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
        list<StudentModel> Students;
    bool error;
    protected:
    public:
        Student();
        ~Student();
        Student* setCode(int code);
        int getCode();
        Student* setName(string name);
        string getName();
        Student* setAverage(float average);
        string getName();
};
Student::Student()
{
    this->Students.clear();
    this->error=false;
};
Student::~Student()
{

};
Student* Student::setCode(int code)
{
    this->studentModel.code = code;
    return this;
}
int Student::getCode()
{
    return this->studentModel.code;
}
Student* Student::setName(string name)
{
    this->studentModel.name = name;
    return this;
}
string Student::getName()
{
    return this->studentModel.name;
}
Student* Student::setAverage(float average)
{
    this->studentModel.average = average;
    return this;
}
int Student::getCode()
{
    return this->studentModel.average;
}
