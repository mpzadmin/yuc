#include <iostream>
#include <list>
#include <fstream>
#include <string>

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

        string errorMessage;
    public:
        Student();
       ~Student(); 
       void debug();

       Student* setcode(int code);
       int getcode();

       Student* setname(string name);
       string getname();

       Student* setaverage(float average);
       float getaverage(); 


       Student* list();
       Student* add();

       bool fail();
       string getError();  
};  

Student :: Student()
{
    this->students.clear();
    this->error = false;
}
Student :: ~Student()
{

} 

void Student::debug()
{
    cout << endl;
    cout << "****************" <<endl;
    cout << "code: "<<this->getcode()<<endl;
    cout << "name: "<<this->getname() <<endl;
    cout << "average: "<<this->getaverage() << endl;
    cout << "************" <<endl;
}

bool Student::fail()
{
    return this->error;
}

string Student::getError()
{
    return this->error ? this->errorMessage : "";
}

Student* Student:: setcode(int code)
{
    this->studentModel.code=code;
    return this;
}

int Student:: getcode()
{
    return this->studentModel.code;
}

Student* Student::setname(string name)
{
    this->studentModel.name=name;
    return this;
}
string Student::getname()
{
    return this->studentModel.name;
}

Student* Student::setaverage(float average)
{
    this->studentModel.average=average;
    return this;
}
float Student::getaverage()
{
    return this->studentModel.average;
}

Student* Student::list()
{
    if (this->students.size() <= 0)
    {
        return this;
    }
    for (StudentModel stu : this -> students)
    {
        cout << "code: " << stu.code << endl;
        cout << "name: " << stu.name << endl;
        cout << "average: " << stu.average << endl;
        cout << endl;
    }

    
    return this;
}

Student* Student::add()
{
    this->students.push_back(this->studentModel);
    return this;
}
