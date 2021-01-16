#include <iostream>
#include <string>
#include <fstream>
#include <list>

using namespace std;

class StudentModel 
{
    public:
        int id;
        int code;
        string name;
        float average;
};

class Student
{
    private:
        StudentModel studentModel;
        list <StudentModel> students;

        bool error;

        string errorMessage;
    protected:
    public:
        Student();
        ~Student();
        debug();

        Student* setCode(int code);
        int getCOde();
        Student* setName(string name);
        string getName();
        Student* setAverage(int average);
        int getAverage();
            

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

void Student::debuge()
{
    cout << endl;
    cout << "****************************" << endl;
    cout << "Code: " << this->getCode() << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Average: " << this->getAverage() << endl;
    cout << "****************************" << endl;



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

int Student::getcode();
{
  return  this->studentModel.code;
}

Student* Student::setName(string name)
{
    this->studentModel.name = name;
    return this;
}

string Student::getname();
{
  return  this->studentModel.name;
}

Student* Student::setAverage(int average)
{
    this->studentModel.average = average;
    return this;
}

int Student::getAvarage();
{
  return  this->studentModel.average;
}
