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
//typedef list <StudentModel>::iterator It;
class Student
{
    private:
        StudentModel studentModel;
        list<StudentModel> Students;
    bool error;
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
};
Student::Student()
{
    this->Students.clear();
    this->error=false;
};
Student::~Student()
{

};
void Student::debug()
{
    cout << "code: " << this->getCode() << endl;
    cout << "name: " << this->getName() << endl;
    cout << "average: " << this->getAverage() << endl;
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
Student* Student::list()
{
    if(this->Students.size() <=0)
    {
        return this;
    }
    for(StudentModel stu : this->Students)
    {
        cout << "code: " << stu.code << endl;
        cout << "name: " << stu.name << endl;
        cout << "average: "<<stu.average <<endl;
        cout << "****************************" <<endl;
    }
    return this;
}
/*Student* Student::list2()
{
    if(this->Students.size() <=0)
    {
        return this;
    }
    for(It it=this->student.begin(); it!=this->student.end(); it++)
    {
        cout << "code: " << it->code << endl;
        cout << "name: " << it->name << endl;
        cout << "average: "<<it->average <<endl;
        cout << "****************************" <<endl;
    }
    return this;
}*/
Student* Student::add()
{
    this->Students.push_back(this->studentModel);
    return this;
}
