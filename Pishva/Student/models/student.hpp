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

typedef list<StudentModel>::iterator StudentIterator;

class Student
{
    private:
        StudentModel studentModel;
        list<StudentModel> students;

        bool error;

        string errorMassage;    
    protected:
    public:
        Student();
        ~Student();
        void debug();

        Student* setCode(int code);
        int getCode();
        Student* setName(string name);
        string getName();
        Student* setAverage(float avarage);
        float getAverage();

        Student* list();
        Student* add();

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
void Student:: debug()
{
    cout << endl;
    cout << "***********************************" << endl;
    cout << "Code: " << this->getCode() << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Avetage: " << this->getAverage() << endl;
    cout << "**********************************" << endl; 
}
bool Student::fail()
{
    return this->error;
}
string Student::getError()
{
    return this->error ? this->errorMassage : "";
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
Student* Student::list()
{
    if (this->students.size() <= 0)
        return this;

    for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
    {
        cout << "Code: " << it->code << endl;
        cout << "Name: " << it->name << endl;
        cout << "Average: " << it->average << endl;
        cout << endl;    
    }

    return this;
}
Student* Student::add()
{
    this->students.push_back(this->studentModel);
    return this;
}
