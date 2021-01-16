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

typedef list<StudentModel>::iterator StudentIterator;

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

        Student* list();
        Student* add();

        void debug();

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

Student* Student::list()
{
    if (this->students.size() <= 0)
        return this;

    // for (StudentModel stu : this->students)
    // {
    //     cout << "Code   : " << stu.code << endl;
    //     cout << "Name   : " << stu.name << endl;
    //     cout << "Average: " << stu.average << endl;
    //     cout << "----------------------------" << endl;
    // }

    for (StudentIterator it = students.begin(); it != students.end(); it++)
    {
        cout << "Code   : " << it->code << endl;
        cout << "Name   : " << it->name << endl;
        cout << "Average: " << it->average << endl;
        cout << "----------------------------" << endl;
    }
    
    return this;
}

Student* Student::add()
{
    this->students.push_back(this->studentModel);
    return this;
}

void Student::debug()
{
    cout << endl;
    cout << "***********************************" << endl;
    cout << "Code: " << this->getCode() << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Average: " << this->getAverage() << endl;
    cout << "***********************************" << endl;
}

bool Student::fail()
{
    return this->error;
}

string Student::getError()
{
    return this->error ? this->errorMessage : "";
}
