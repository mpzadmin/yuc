#include <iostream>
#include <string>
#include <list>

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

        Student* setCode(int code);
        Student* setName(string name);
        Student* setAverage(float average);

        int getCode();
        string getName();
        float getAverage();

        Student* list();
        Student* add();
        Student* remove();
        
        bool find(Field searchField);

        void debug();

        bool fail();
        Student* clearError();
        Student* setError(string errorMessage);
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
    this->clearError();

    if (!this->find(Field::Code))
    {
        this->students.push_back(this->studentModel);
    }
    else
    {
        this->setError("The data exists!");
    }
    return this;
}

Student* Student::remove()
{
    this->clearError();
    bool result = false;
    for (StudentIterator it = students.begin(); it != students.end(); it++)
    {
        if (it->code == this->studentModel.code)
        {
            this->students.erase(it);
            result = true;
            break;
        }
    }
    if (!result)
    {
        this->setError("Not Found!");
    }
    return this;
}

bool Student::find(Field searchField)
{
    bool result = false;
    for (StudentIterator it = students.begin(); it != students.end(); it++)
    {
        if (searchField == Field::Code)
        {
            if (it->code == studentModel.code)
            {
                this->studentModel = *it;
                result = true;
                break;
            }
        }
        else if (searchField == Field::Name)
        {
            if (it->name == studentModel.name)
            {
                this->studentModel = *it;
                result = true;
                break;
            }
        }
        else
        {
            if (it->average == studentModel.average)
            {
                this->studentModel = *it;
                result = true;
                break;
            }
        }
    }
    return result;
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

Student* Student::clearError()
{
    this->error = false;
    this->errorMessage.clear();
    return this;
}

Student* Student::setError(string errorMessage)
{
    this->error = true;
    this->errorMessage = errorMessage;
    return this;
}

string Student::getError()
{
    return this->error ? this->errorMessage : "";
}
