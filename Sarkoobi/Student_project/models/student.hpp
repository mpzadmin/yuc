#include <iostream>
#include <string>
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
        StudentModel studentmodel;
        list<StudentModel> students;

        bool error;

        string errorMessage;
    protected:

    public:
        Student();
        ~Student();
        Student* setcode(int code);
        int getcode();
        Student* setName(string name);
        string getName();
        Student* setAverage(float average);
        float getAverage();
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

Student* Student::setcode(int code)
{
    this->studentmodel.code = code;
    return this;
}

int Student::getcode()
{
    return this->studentmodel.code;
}
Student* Student::setName(string name)
{
    
}


