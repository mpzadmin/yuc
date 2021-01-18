#include <iostream>
#include <string>
#include <fstream>
#include <list>

using namespace std;

typedef list<StudentModel>:: iterator StudentModelIterator;
enum Field{Code, Name, Average};

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
        list <StudentModel> students;

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
        Student* setAverage(int average);
        float getAverage();

        Student* list();
        Student* add();

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

void Student::debug()
{
    cout << endl;
    cout << "****************************" << endl;
    cout << "Code: " << this->getCode() << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Average: " << this->getAverage() << endl;
    cout << "****************************" << endl;



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
  return  this->studentModel.code;
}

Student* Student::setName(string name)
{
    this->studentModel.name = name;
    return this;
}

string Student::getName()
{
  return  this->studentModel.name;
}

Student* Student::setAverage(int average)
{
    this->studentModel.average = average;
    return this;
}

float Student::getAverage()
{
  return  this->studentModel.average;
}
//iterator
Student* Student::list()
{
    if (this->students.size() <= 0)
    {
        return this;
    }
    for(StudentModelIterator it=this->students.begin(); it != this->students.end(); it++ )
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

bool Student::find(Field searchField)
{
    bool result = false;
    if (this->students.size() <= 0) return result;
    for(StudentModelIterator it=this->students.begin(); it != this->students.end(); it++ )
    {
        if (searchField == Field::Code)
        {
            if (it->code == this->studentModel.code)
            {
                this->studentModel= *it;
                result = true;
                break;
            }
        }
        else if (searchField == Field::Name)
        {
            if (it->name == this->studentModel.name)
            {
                this->studentModel= *it;
                result = true;
                break;
            }

        }
        else
        {
            if (it->average == this->studentModel.average)
            {
                this->studentModel= *it;
                result = true;
                break;
            }
            
        }
        
    }
    return result;
}

