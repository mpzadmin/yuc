/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

/** External Libraries **/
#include <iostream>
#include <string>
#include <list>
#include <fstream>

/** Namespaces **/
using namespace std;

/** Enums **/
enum Field {Code, Name, Average};
enum SortMode {Asc, Desc};

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
typedef list<StudentModel>::reverse_iterator RStudentIterator;

class Student
{
    private:
        StudentModel studentModel;
        list<StudentModel> students;

        size_t limitCount;
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
        string getName(int code);
        string getName();
        Student* setAverage(float avg);
        float getAverage();

        Student* list(bool showFilteredData = false);
        Student* add();
        Student* remove();

        bool find(Field searchField);
        Student* filter(Field filterField);
        Student* sort(Field sortField, SortMode sortMode = SortMode::Asc);
        Student* limit(size_t count);
        Student* first(bool filteredData = false);
        Student* last(bool filteredData = false);

        bool fail();
        Student* setError(const string& err);
        string getError();
        Student* clearError();
};

// Student construction
Student::Student()
{
    this->students.clear();
    this->error = false;
}

// Student deconstruction
Student::~Student() {}

// Prints the current student data.
void Student::debug()
{
    cout << endl;
    cout << "************************************************" << endl;
    cout << "Code: " << this->getCode() << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Average: " << this->getAverage() << endl;
    cout << "************************************************" << endl;
}

// Sets the code of the current student.
Student* Student::setCode(int code)
{
    this->studentModel.code = code;
    return this;
}

// Gets the code of the current student.
int Student::getCode()
{
    return studentModel.code;
}

// Sets the name of the current student.
Student* Student::setName(string name)
{
    this->studentModel.name = name;
    return this;
}

// Gets the code of the current student.
string Student::getName(int code)
{
    return studentModel.name;
}

// Checks if there are any errors.
bool Student::fail()
{
    return this->error;
}

// Returns the error if exists.
string Student::getError()
{
    return this->error ? this->errorMessage : "";
}

// Sets the average of the current student.
Student* Student::setAverage(float avg)
{
    this->studentModel.average = avg;
    return this;
}

// Gets the average of the current student.
float Student::getAverage()
{
    return this->studentModel.average;
}

// Prints the students.
Student* Student::list(bool showFilteredData)
{
    if (this->students.empty())
    {
        return this;
    }

    for (auto &student : this->students)
    {
        if (showFilteredData && (!student.filtered))
            continue;

        cout << "Code: " << student.code << endl;
        cout << "Name: " << student.name << endl;
        cout << "Average: " << student.average << endl;
        cout << endl;
    }

    return this;
}

// Adds a new student.
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

// Removes a student.
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

// Finds a student.
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

// Filters the students by a field.
Student* Student::filter(Field filterField)
{
    this->clearError();
    for (auto &student : this->students)
    {
        student.filtered = false;

        if (filterField == Field::Code)
        {
            if (student.code == this->studentModel.code)
                student.filtered = true;
        }
        else if (filterField == Field::Name)
        {
            if (student.name == this->studentModel.name)
                student.filtered = true;
        }
        else if (filterField == Field::Average)
        {
            if (student.average == this->studentModel.average)
                student.filtered = true;
        }
    }

    return this;
}

// Sorts the students by a field.
Student* Student::sort(Field sortField, SortMode sortMode)
{
    StudentIterator it, it2;
    StudentModel st;

    it = this->students.begin();

    while (it != students.end())
    {
        it2 = it;
        it2++;

        while (it2 != this->students.end())
        {
            if (sortField == Field::Code)
            {
                if (sortMode == SortMode::Asc) // Asc
                {
                    if (it->code > it2->code)
                    {
                        // Swapping it and it2
                        st = *it;
                        *it = *it2;
                        *it2 = st;
                    }
                }
                else // Desc
                {
                    if (it->code < it2->code)
                    {
                        // Swapping it and it2
                        st = *it;
                        *it = *it2;
                        *it2 = st;
                    }
                }
            }
            else if (sortField == Field::Average)
            {
                if (sortMode == SortMode::Asc) // Asc
                {
                    if (it->average > it2->average)
                    {
                        // Swapping it and it2
                        st = *it;
                        *it = *it2;
                        *it2 = st;
                    }
                }
                else // Desc
                {
                    if (it->average < it2->average)
                    {
                        // Swapping it and it2
                        st = *it;
                        *it = *it2;
                        *it2 = st;
                    }
                }
            }
            else if (sortField == Field::Name)
            {
                if (sortMode == SortMode::Asc) // Asc
                {
                    if (it->name > it2->name)
                    {
                        // Swapping it and it2
                        st = *it;
                        *it = *it2;
                        *it2 = st;
                    }
                }
                else // Desc
                {
                    if (it->name < it2->name)
                    {
                        // Swapping it and it2
                        st = *it;
                        *it = *it2;
                        *it2 = st;
                    }
                }
            }

            it2++;
        }
        it++;
    }

    return this;
}

// Limits the list of students.
Student* Student::limit(size_t count)
{
    this->limitCount = count;
    return this;
}

// Gets the first student.
Student* Student::first(bool filteredData)
{
    if (filteredData)
    {
        for (StudentIterator it = this->students.begin(); it != students.end(); ++it)
        {
            if (it->filtered)
            {
                this->studentModel = *it;
                return this;
            }
        }
    }
    else
    {
        this->studentModel = this->students.front();
    }

    return this;
}

// Gets the last student.
Student* Student::last(bool filteredData)
{
    if (filteredData)
    {
        for (RStudentIterator rIt = this->students.rbegin(); rIt != students.rend(); ++rIt)
        {
            if (rIt->filtered)
            {
                this->studentModel = *rIt;
                return this;
            }
        }
    }
    else
    {
        this->studentModel = this->students.back();
    }

    return this;
}

// Sets an error that can be read later.
Student* Student::setError(const string &err)
{
    this->error = true;
    this->errorMessage = err;

    return this;
}

// Clears the error.
Student* Student::clearError()
{
    this->error = false;
    this->errorMessage.clear();

    return this;
}
