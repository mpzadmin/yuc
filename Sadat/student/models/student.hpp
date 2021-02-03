#include <iostream>
#include <windows.h>
#include <list>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
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
            this->filtered = false;
        }
};

typedef list<StudentModel>::iterator StudentItr;
typedef list<StudentModel>::reverse_iterator RStudentItr;

class Student
{
    private:
        StudentModel studentModel;
        list<StudentModel> students;
        string errorMessage;
        size_t limitCount;
        bool error;
    protected:
    public:
        Student();
        ~Student();

        Student* setCode(int code);
        Student* setName(string name);
        Student* setAverage(float average);
        int getCode();
        string getName();
        float getAverage();

        Student* list(bool showFilteredData = false);
        Student* first(bool filteredData = false);
        Student* last(bool filteredData = false);
        Student* limit(size_t count);
        Student* add();
        Student* clearError();
        Student* setError(string errorMessage);
        Student* remove(int code);

        void debug();
        bool find(Field searchField);
        Student* filter(Field filterField);
        Student* sort(Field sortField, SortMode sortMode);
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

bool Student::fail()
{
    return this->error;
}

string Student::getError()
{
    return (this->error) ? this->errorMessage : "";
}

Student* Student::setCode(int code)
{
    this->studentModel.code = code;
    return this;
}

Student* Student::setName(string name)
{
    this->studentModel.name = name;
    return this;
}

Student* Student::setAverage(float average)
{
    this->studentModel.average = average;
    return this;
}

int Student::getCode()
{
    return this->studentModel.code;
}

string Student::getName()
{
    return this->studentModel.name;
}

float Student::getAverage()
{
    return this->studentModel.average;
}

void Student::debug()
{
    cout << "<<< Code: ";
    SetConsoleTextAttribute(console, 4);
    cout << this->getCode();
    SetConsoleTextAttribute(console, 7);
    cout << " - Name: ";
    SetConsoleTextAttribute(console, 2);
    cout << this->getName();
    SetConsoleTextAttribute(console, 7);
    cout << " - Average: ";
    SetConsoleTextAttribute(console, 5);
    cout << this->getAverage();
    SetConsoleTextAttribute(console, 7);
    cout << " >>>" << endl;
}

Student* Student::list(bool showFilteredData)
{
    if (this->students.size() <= 0) return this;
    for (StudentModel model : this->students)
    {
        if (showFilteredData && !model.filtered) continue;
        cout << "*** Code: ";
        SetConsoleTextAttribute(console, 4);
        cout << model.code;
        SetConsoleTextAttribute(console, 7);
        cout << ", Name: ";
        SetConsoleTextAttribute(console, 2);
        cout << model.name;
        SetConsoleTextAttribute(console, 7);
        cout << ", Average: ";
        SetConsoleTextAttribute(console, 5);
        cout << model.average;
        SetConsoleTextAttribute(console, 7);
        cout << " *** " << endl;
    }
    return this;
}

Student* Student::add()
{
    this->setError("The entered student code exists in another student's informaion!");
    if (!this->find(Field::Code))
    {
        this->students.push_back(this->studentModel);
        this->clearError();
    }
    return this;
}

bool Student::find(Field searchField)
{
    bool result = false;
    for (StudentModel stu : this->students)
    {
        switch(searchField)
        {
            // Search by code
            case Field::Code:
                if (this->studentModel.code == stu.code) 
                {
                    result = true;
                    this->studentModel = stu;
                }
                break;
            // Search by name
            case Field::Name:
                if (this->studentModel.name == stu.name) 
                {
                    result = true;
                    this->studentModel = stu;
                }
                break;
            // Search by average
            case Field::Average:
                if (this->studentModel.average == stu.average) 
                {
                    result = true;
                    this->studentModel = stu;
                }
                break;
        }
        if (result) break;
    }
    return result;
}

Student* Student::clearError()
{
    this->error = false;
    this->errorMessage = "";
    return this;
}

Student* Student::setError(string errorMessage)
{
    this->error = true;
    this->errorMessage = errorMessage;
    return this;
}

Student* Student::remove(int code)
{
    this->setError("Coudn't find any student with given code!");
    for (StudentItr studentItr = this->students.begin(); studentItr != this->students.end(); studentItr++)
    {
        if (studentItr->code == code)
        {
            this->students.erase(studentItr);
            this->clearError();
            break;
        }
    }
    return this;
}

Student* Student::filter(Field filterField)
{
    this->clearError();
    for (StudentItr studentItr = this->students.begin(); studentItr != this->students.end(); studentItr++)
    {
        studentItr->filtered = false;
        switch(filterField)
        {
            // Filter by code
            case Field::Code:
                if (this->studentModel.code == studentItr->code) 
                {
                    studentItr->filtered = true;
                }
                break;
            // Filter by name
            case Field::Name:
                if (this->studentModel.name == studentItr->name) 
                {
                    studentItr->filtered = true;
                }
                break;
            // Filter by average
            case Field::Average:
                if (this->studentModel.average == studentItr->average) 
                {
                    studentItr->filtered = true;
                }
                break;
        }
    }
    return this;
}

Student* Student::sort(Field sortField, SortMode sortMode)
{
    StudentItr itr1, itr2;
    StudentModel stu;
    itr1 = this->students.begin();

    while(itr1 != this->students.end())
    {
        itr2 = itr1;
        itr2++;
        while(itr2 != this->students.end())
        switch(sortField)
        {
            case Field::Code:
                if (sortMode == SortMode::Asc)
                {
                    if (itr1->code > itr2->code)
                    {
                        stu = *itr1;
                        *itr1 = *itr2;
                        *itr2 = stu;
                    }
                }
                else if (sortMode == SortMode::Desc)
                {
                    if (itr1->code < itr2->code)
                    {
                        stu = *itr1;
                        *itr1 = *itr2;
                        *itr2 = stu;
                    }
                }
                break;
            case Field::Name:
                if (sortMode == SortMode::Asc)
                {
                    if (itr1->name > itr2->name)
                    {
                        stu = *itr1;
                        *itr1 = *itr2;
                        *itr2 = stu;
                    }
                }
                else if (sortMode == SortMode::Desc)
                {
                    if (itr1->name < itr2->name)
                    {
                        stu = *itr1;
                        *itr1 = *itr2;
                        *itr2 = stu;
                    }
                }
                break;
            case Field::Average:
                if (sortMode == SortMode::Asc)
                {
                    if (itr1->average > itr2->average)
                    {
                        stu = *itr1;
                        *itr1 = *itr2;
                        *itr2 = stu;
                    }
                }
                else if (sortMode == SortMode::Desc)
                {
                    if (itr1->average < itr2->average)
                    {
                        stu = *itr1;
                        *itr1 = *itr2;
                        *itr2 = stu;
                    }
                }
                break;
        }
    }
    return this;
}

Student* Student::limit(size_t count)
{
    this->limitCount = count;
    return this;
}

Student* Student::first(bool filteredData)
{
    if (filteredData)
    {
        for (StudentItr studentItr = this->students.begin(); studentItr != this->students.end(); studentItr++)
        {
            if (studentItr->filtered)
            {
                this->studentModel = *studentItr;
                break;
            }
        }
    }
    else
    {
        this->studentModel = this->students.front();
    }
    return this;
}

Student* Student::last(bool filteredData)
{
    if (filteredData)
    {
        for (RStudentItr studentItr = this->students.rbegin(); studentItr != this->students.rend(); studentItr++)
        {
            if (studentItr->filtered)
            {
                this->studentModel = *studentItr;
                break;
            }
        }
    }
    else
    {
        this->studentModel = this->students.back();
    }
    return this;
}