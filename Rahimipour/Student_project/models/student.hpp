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

typedef list<StudentModel>::iterator StudentIterator;// SMIterator : student

class Student // main class
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
        void debug(); // to show data 

        Student* setCode(int code);
        int getCode();

        Student* setName(string name);
        string getName();

        Student* setAverage(float average);
        float getAverage();

        //Student* list();// print all data in list sutdent.
        Student* list2();

        Student* add();// 
        Student* remove();
        bool find(Field searchField); // we want to return true or false.

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

void Student::debug()
{
    cout << endl;
    //cout << "*************" << endl;
    cout << "Code: " << this->getCode() << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Average: " << this->getAverage() << endl;
    cout << "*************" << endl;
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
/* the buttom code down this one is more profetional.
Student* Student::list()
{
    if (this->students.size() <= 0)
    {
        return this;
    }

    for (StudentModel stu : this->students)
    {
        cout << "Code: " << stu.code << endl;
        cout << "Name: " << stu.name << endl;
        cout << "Average: " << stu.average << endl;
        cout << "-_-_-_-_-_-_-_-_-_-_-" << endl;
    }

    return this;
}
*/

Student* Student::list2()
{
    if (this->students.size() <= 0)
    {
        return this;
    }

    for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
    {
        cout << "Code: " << it->code << endl;
        cout << "Name: " << it->name << endl;
        cout << "Average: " << it->average << endl;
        cout << "*-*-*-*-*-**-*-*-*-*-*" << endl;
    }

    return this;
}

Student* Student::add()
{
    this->clearError();
    if ( !this->find(Field::Code) )
    {
        this->students.push_back(this->studentModel);
    }

    else 
    {
        this->setError("The record exists!");
    }
    return this;
}

Student* Student::remove()
{
    bool result = false;
    this->clearError();
    for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
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
        this->setError("The record not found!");
    }
    return this;
}

bool Student::find(Field searchField)
{
    bool result = false;
    if (this->students.size() <= 0)
    {
        return result;
    }
    for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
    {
        if (searchField == Field::Code)
        {
            if (it->code == this->studentModel.code)
            {
                /** we can use this. or down of it which is not comment.
                this->setCode(it->code);
                this->setName(it->name);
                this->setAverage(it->average);
                */
                this->studentModel = *it;
                result = true;
                break;
            }
        }

        else if (searchField == Field::Name)
        {
            if (it->name == this->studentModel.name)
            {
                this->studentModel = *it;
                result = true;
                break;
            }
            
        }

        else // will be average
        {
            if (it->average == this->studentModel.average)
            {
                this->studentModel = *it;
                result = true;
                break;
            }
             
        }
        
    }
    return result;
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



