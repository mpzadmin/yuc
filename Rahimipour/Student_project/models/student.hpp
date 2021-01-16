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
        string errorMessage;
    protected:
    public:
        Student();
        ~Student();
        void debug(); // to show data 

        Student* setCode(int code);
        int getCode();

        Student* setName(string name);
        string getName();

        Student* setAverage(float average);
        float getAverage();

       

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

void Student::debug()
{
    cout << endl;
    cout << "*************" << endl;
    cout << "Code: " << this->getCode() << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Average: " << this->getAverage() << endl;
    cout << "*************" << endl;
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

float Student::getAverage()
{
    return this->studentModel.average;
}



