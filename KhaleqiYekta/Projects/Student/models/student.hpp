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

enum Field {Code, Name, Average};

class StudentModel
{
    public:
        int code;
        string name;
        float average;
        bool filtered;
        StudentModel()
        {
            filtered = false; // false by default
        }
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
        int getCode();
        Student* setName(string name);
        string getName(int code);
        string getName();
        Student* setAverage(float avg);
        float getAverage();

        Student* list();
        Student* add();
        Student* remove();

        bool find(Field searchField);
        Student* filter(Field filterField);

        void debug();

        bool fail();
        Student* setError(const string& err);
        string getError();
        Student* clearError();
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

Student* Student::list()
{
    if (this->students.empty())
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

Student* Student::add()
{
    this->clearError();

    if (!this->find(Field::Code))
    {
        this->students.push_back(this->studentModel);
    }
    else
    {
        this->setError("Record already exists!");
    }

    return this;
}

Student* Student::remove()
{
    bool result = false;
    this->clearError();

    for (StudentIterator it = this->students.begin(); it != this->students.end(); ++it)
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
        this->setError("Record not found!");
    }

    return this;
}

bool Student::find(Field searchField)
{
    bool result = false;

    if (this->students.empty())
    {
        return result;
    }

    for (StudentIterator it = this->students.begin(); it != students.end(); ++it)
    {
        if (searchField == Field::Code)
        {
            if (it->code == this->studentModel.code)
            {
                result = true;
                this->studentModel = *it;

                break;
            }
        }
        else if (searchField == Field::Name)
        {
            result = true;
            this->studentModel = *it;

            break;
        }
        else
        {
            result = true;
            this->studentModel = *it;

            break;
        }
    }

    return result;
}

Student* Student::filter(Field filterField)
{
    this->clearError();
    for (StudentIterator it = this->students.begin(); it != this->students.end(); ++it)
    {
        it->filtered = false;

        if (filterField == Field::Code)
        {
            if (it->code == this->studentModel.code)
                it->filtered = true;
        }
        else if (filterField == Field::Name)
        {
            if (it->name == this->studentModel.name)
                it->filtered = true;
        }
        else if (filterField == Field::Average)
        {
            if (it->average == this->studentModel.average)
                it->filtered = true;
        }
    }

    return this;
}

Student* Student::setError(const string &err)
{
    this->error = true;
    this->errorMessage = err;

    return this;
}

Student* Student::clearError()
{
    this->error = false;
    this->errorMessage.clear();

    return this;
}