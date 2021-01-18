#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

enum Field {Code, Name, Average};

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
        void debug();

        Student* setCode(int code);
        int getCode();
        Student* setName(string name);
        string getName();
        Student* setAverage(float avrage);
        float getAverage();

        Student* add();
        Student* list();

        bool find(Field searchFeild);

        bool fail();
        Student* clearError();
        Student* setError(string errorMessage);
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

Student* Student::setAverage(float avrage)
{
    this->studentModel.average = avrage;
    return this;
}

float Student::getAverage()
{
    return this->studentModel.average;
}

Student* Student::list()
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

Student* Student::add()
{
    if (!this->find(Field::Code))
    {
        this->students.push_back(studentModel);
    }
    else
    {
        this->setError("The record exists!");
    }
    
    return this;
}

bool Student::find(Field searchFeild)
{
    bool result = false;
    if (this->students.size() <= 0) return result;
    for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
    {
        if ((searchFeild == Field::Code && it->code == this->studentModel.code) ||
            (searchFeild == Field::Name && it->name == this->studentModel.name) ||
            (searchFeild == Field::Average && it->average == this->studentModel.average))
        {
                studentModel = *it;
                result = true;
                break;
        }
    }
    return result;
}

Student* Student::clearError()
{
    error = false;
    this->errorMessage.clear();
    return this;
}

Student* Student::setError(string errorMessage)
{
    error = true;
    this->errorMessage = errorMessage;
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