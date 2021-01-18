#include <iostream>
#include <windows.h>
#include <list>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
enum Field {Code, Name, Average};

class StudentModel
{
    public:
        int code;
        string name;
        float average;
};

typedef list<StudentModel>::iterator StudentItr;

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
        Student* clearError();
        Student* setError(string errorMessage);
        Student* remove(int code);

        void debug();
        bool find(Field searchField);
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
    cout << "<<< Code: ";
    SetConsoleTextAttribute(console, 4);
    cout << this->getCode();
    SetConsoleTextAttribute(console, 7);
    cout << " - Name: ";
    SetConsoleTextAttribute(console, 2);
    cout << this->getName();
    SetConsoleTextAttribute(console, 7);
    cout << " - Average: ";
    SetConsoleTextAttribute(console, 5);
    cout << this->getAverage();
    SetConsoleTextAttribute(console, 7);
    cout << " >>>" << endl;
}

Student* Student::list()
{
    if (this->students.size() <= 0) return this;
    for (StudentModel model : this->students)
    {
        cout << "*** Code: ";
        SetConsoleTextAttribute(console, 4);
        cout << model.code;
        SetConsoleTextAttribute(console, 7);
        cout << ", Name: ";
        SetConsoleTextAttribute(console, 2);
        cout << model.name;
        SetConsoleTextAttribute(console, 7);
        cout << ", Average: ";
        SetConsoleTextAttribute(console, 5);
        cout << model.average;
        SetConsoleTextAttribute(console, 7);
        cout << " *** " << endl;
    }
    return this;
}

Student* Student::add()
{
    this->setError("The entered student code exists in another student's informaion!");
    if (!this->find(Field::Code))
    {
        this->students.push_back(this->studentModel);
        this->clearError();
    }
    return this;
}

bool Student::find(Field searchField)
{
    bool result = false;
    for (StudentModel stu : this->students)
    {
        switch(searchField)
        {
            // Search by code
            case 0:
                if (this->studentModel.code == stu.code) 
                {
                    result = true;
                    this->studentModel = stu;
                }
                break;
            // Search by name
            case 1:
                if (this->studentModel.name == stu.name) 
                {
                    result = true;
                    this->studentModel = stu;
                }
                break;
            // Search by average
            case 2:
                if (this->studentModel.average == stu.average) 
                {
                    result = true;
                    this->studentModel = stu;
                }
                break;
        }
        if (result) break;
    }
    return result;
}

Student* Student::clearError()
{
    this->error = false;
    this->errorMessage = "";
    return this;
}

Student* Student::setError(string errorMessage)
{
    this->error = true;
    this->errorMessage = errorMessage;
    return this;
}

Student* Student::remove(int code)
{
    this->setError("Coudn't find any student with given code!");
    for (StudentItr studentItr = this->students.begin(); studentItr != this->students.end(); studentItr++)
    {
        if (studentItr->code == code)
        {
            this->students.erase(studentItr);
            this->clearError();
            break;
        }
    }
    return this;
}