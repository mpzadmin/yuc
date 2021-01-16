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
        void debug();

        Student* setCode(int code);
        int getCode();
        Student* setName(string name);
        string getName();
        Student* setAverage(float avrage);
        float getAverage();

        Student* list();

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

Student* Student::setName(string name)
{
    this->studentModel.name = name;
}

string Student::getName()
{
    this->studentModel.name;
}

Student* Student::setAverage(float avrage)
{
    this->studentModel.average = avrage;
}

float Student::getAverage()
{
    return this->studentModel.average;
}

Student* Stusent::list()
{
    if(this->students.size() <= 0)
        return this;
    
    for(StudentModel stu : this->students)
    {
        cout << "code: " << this->studentModel.code << endl;
        cout << "name: " << this->studentModel.name << endl;
        cout << "avrage: " << this->studentModel.average << endl;
    }
    return this;
}

void Student::debug()
{
    cout << endl;
    cout << "************************" << endl;
    cout << "code: " << this->studentModel.code << endl;
    cout << "name: " << this->studentModel.name << endl;
    cout << "avrage: " << this->studentModel.average << endl;
    cout << "************************" << endl;
}