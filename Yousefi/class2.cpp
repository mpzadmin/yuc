#include <iostream>
#include <string>

using namespace std;

class Student
{
    private:
        int code;
        string name;
    public:
        Student();
       ~Student();
        void setname(string name);
        string getname();
        void setcode(int code);
        int getcode();
};

Student :: Student()
{
    cout << "init Student class "<<endl;
}

Student :: ~Student()
{
    cout << "destroy Student class " << endl;
}

void Student :: setname(string name)
{
    this->name=name;
    cout << "name: " << name << endl;
}

string Student:: getname()
{
    return name;
}

void Student:: setcode(int code)
{
    this->code=code;
    cout << "code: " << code << endl;
}

int Student:: getcode()
{
    return code;
}

int main(int argc, char const *argv[])
{
    
    

    Student* student;

    student = new Student;

    student->setname("ali");
    student->setcode(110);

    student->setname("habib");
    student->setcode(156);

    student->setname("reza");
    student->setcode(147);

    delete student;

    return 0;
}
