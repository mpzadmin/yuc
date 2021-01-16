#include<iostream>
#include<fstream>
#include<string>
#include<list>

using namespace std;

class StudentModel
{
     public:
         int code;
         string name;
         float avarage;

};

typedef list<StudentModel>::iterator StudentIterator;


class Student
{
     private:
         StudentModel studentModel;
         list <StudentModel> students;

         bool error;

         string errorMessage;

     public:
         Student();
         ~Student();

         void debug();

         Student* setCode(int code);
         int getCode();
         Student* setName(string name);
         string getName();
         Student* setAvarage(float avarage);
         float getAverage();

         Student* list();
        // Student* list2();
         Student* add();

         bool fail();
         string getError();



};

Student::Student()
{
     this-> students.clear();
     this-> error = false;
}

Student:: ~Student()
{

}

void Student:: debug()
{
    cout << "\n" ;
    cout << "***************************" <<endl;
    cout << "code: " << this -> getCode()  << endl;
    cout << "Name : "<< this -> getName() << endl;
    cout << "Avarage : " << this-> getAverage()<< endl;
    cout << "\n";

}

bool Student :: fail()
{
    return this->error;
}

string Student :: getError()
{
     return this->error ? this->errorMessage : "";
}

Student* Student::setCode(int code)
{
    this-> studentModel.code = code;
    return this;
}

int Student :: getCode()
{
    return this-> studentModel.code;
}

Student* Student::setName(string name)
{
    this-> studentModel.name = name;
    return this;
}

string Student :: getName()
{
    return this -> studentModel.name;
}

Student* Student :: setAvarage(float avarage)
{
    this-> studentModel.avarage = avarage;
    return this;

}

float Student :: getAverage()
{
    return this -> studentModel.avarage;
}

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
        cout << "Average: " << stu.avarage << endl;
        cout << endl;    
    }

    return this;
}
/*
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
        cout << endl;    
    }

    return this;
}
*/
Student* Student::add()
{
    this->students.push_back(this->studentModel);
    return this;
}



