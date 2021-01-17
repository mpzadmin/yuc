#include <iostream>
#include <windows.h>
#include <list>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

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
        string errorMessage;
        bool error;
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
    return (this->error) ? this->errorMessage : "";
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

void Student::debug()
{
    SetConsoleTextAttribute(console, 2);
    cout << "*** Code: " << this->getCode() << " ***" << endl;
    SetConsoleTextAttribute(console, 4);
    cout << "*** Name: " << this->getName() << " ***" << endl;
    SetConsoleTextAttribute(console, 6);
    cout << "*** Average: " << this->getAverage() << " ***" << endl;
    SetConsoleTextAttribute(console, 7);
}

Student* Student::list()
{
    if (this->students.size() <= 0) return this;
    for (StudentModel model : this->students)
    {
        SetConsoleTextAttribute(console, 2);
        cout << "*** Code: " << model.code;
        SetConsoleTextAttribute(console, 4);
        cout << " , Name: " << model.name;
        SetConsoleTextAttribute(console, 6);
        cout << " , Average: " << model.average << " ***" << endl;
    }
    SetConsoleTextAttribute(console, 7);
    return this;
}

Student* Student::add()
{
    this->students.push_back(this->studentModel);
    return this;
}