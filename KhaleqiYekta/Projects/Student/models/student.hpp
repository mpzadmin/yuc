/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

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
        int getCode();

        Student* setName(string name);
        string getName(int code);
        string getName();

        Student* setAverage(float avg);
        float getAverage();

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

void Student::debug()
{
    cout << endl;
    cout << "************************************************" << endl;
    cout << "Code: " << this->getCode() << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Average: " << this->getAverage() << endl;
    cout << "************************************************" << endl;
}

Student* Student::setCode(int code)
{
    this->studentModel.code = code;
    return this;
}

int Student::getCode()
{
    return studentModel.code;
}

Student* Student::setName(string name)
{
    this->studentModel.name = name;
    return this;
}

string Student::getName(int code)
{
    return studentModel.name;
}

bool Student::fail()
{
    return this->error;
}

string Student::getError()
{
    return this->error ? this->errorMessage : "";
}

Student* Student::setAverage(float avg)
{
    this->studentModel.average = avg;
    return this;
}

float Student::getAverage()
{
    return this->studentModel.average;
}