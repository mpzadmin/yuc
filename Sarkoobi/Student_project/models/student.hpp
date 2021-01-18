#include <iostream>
#include <string>
#include <list>


using namespace std;
enum Field {Code, Name, Average}
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
        StudentModel studentmodel;
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
        Student* setAverage(float average);
        float getAverage();
        Student* list();
        //Student* list2();
        
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
    cout << "*******************************************" << endl;
    cout << "Code: " << this->getCode() << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Average: " << this->getAverage() << endl;
    cout << "*******************************************" << endl;
}

bool Student::fail()
{
    return this->error;
}

string Student::getError()
{
    return this->error ? this->errorMessage : " ";
}

Student* Student::setCode(int code)
{
    this->studentmodel.code = code;
    return this;
}

int Student::getCode()
{
    return this->studentmodel.code;
}
Student* Student::setName(string name)
{
    this->studentmodel.name = name;
    return this;
}

float Student::getAverage()
{
    return this->studentmodel.average;
}
/*
Student* Student::list()
{
    if(this->students.size() <= 0)
    {
        return this;
    }

    for (studentmodel stu : this->students)
    {
        cout << "code: " << stu.code << endl;
        cout << "Name: " << stu.name << endl;
        cout << "Average: " << stu.average << endl;
        cout << endl;
    }
    return this;
} 
*/
Student* Student::list()
{
    if(this->students.size() <= 0)
    {
        return this;
    }

    for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
    {
        cout << "code: " <<it->code << endl;
        cout << "Name: " <<it->name << endl;
        cout << "Average: " <<it->average << endl;
        cout << endl;
    }
    return this;
} 

Student* Student::add()
{
    this->students.push_back(this->studentmodel);
    return this;
}

bool Student::find(Field searchField)
{
    bool result = false;
    if(this->students.size() <= 0)
        return result;
    
    for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
    {
        if (searchField == Field::Code)
        {
            if (it->code == this->studentmodel.code)
            {
                this->studentmodel = *it;
                result true;
                break;
            }
            
        }
        else if (searchField == Field::Name)
        {
            if (it->name == this->studentmodel.name)
            {
                this->studentmodel = *it;
                result true;
                break;
            }
        }
        else
        {
            if (it->average == this->studentmodel.average)
            {
                this->studentmodel = *it;
                result true;
                break;
            }
        }
    }
}