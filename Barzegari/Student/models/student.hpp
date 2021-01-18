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

typedef list<Student>::iterator StudentIterator;

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
    this->students.push_back(studentModel);
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