#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

enum SortMode {Asc, Desc};
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
            filtered = false;
        }
};

typedef list<StudentModel>::iterator StudentIterator;

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
        string getName();
        Student* setAverage(float avrage);
        float getAverage();

        Student* add();
        Student* list(bool showFilteredData = false);
        Student* remove();

        bool find(Field searchFeild);
        Student* filter(Field filterFeild);
        Student* sort(Field sortFeild, SortMode sortMode);
        Student* limit(size_t count);
        Student* first(bool filteredData = false);
        Student* last(bool filteredData = false);

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

bool Student::fail()
{
    return error;
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

Student* Student::setAverage(float avrage)
{
    this->studentModel.average = avrage;
    return this;
}

float Student::getAverage()
{
    return this->studentModel.average;
}

Student* Student::list(bool showFilteredData)
{
    if(this->students.size() <= 0)
        return this;
    
    for(StudentModel stu : this->students)
    {
        if (showFilteredData && (!stu.filtered)) continue;
        cout << "code: " << this->studentModel.code << endl;
        cout << "name: " << this->studentModel.name << endl;
        cout << "avrage: " << this->studentModel.average << endl << endl;
    }
    return this;
}

Student* Student::add()
{
    if (!this->find(Field::Code))
    {
        this->students.push_back(studentModel);
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
        if(it->code == this->studentModel.code)
        {
            this->students.erase(it);
            result = true;
        }
    }
    if(!result)
        this->setError("The record not found!");
    return this;
}

bool Student::find(Field searchFeild)
{
    bool result = false;
    if (this->students.size() <= 0) return result;
    for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
    {
        if ((searchFeild == Field::Code && it->code == this->studentModel.code) ||
            (searchFeild == Field::Name && it->name == this->studentModel.name) ||
            (searchFeild == Field::Average && it->average == this->studentModel.average))
        {
                studentModel = *it;
                result = true;
                break;
        }
    }
    return result;
}

Student* Student::filter(Field filterFeild)
{
    this->clearError();
    for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
    {
        it->filtered = false;
        if ((filterFeild == Field::Code && it->code == this->studentModel.code) ||
            (filterFeild == Field::Name && it->name == this->studentModel.name) ||
            (filterFeild == Field::Average && it->average == this->studentModel.average))
        {
                it->filtered = true;
        }
    }
    return this;
}

Student* Student::sort(Field sortFeild, SortMode sortMode)
{
    StudentIterator it,it2;
    StudentModel stu;

    it = this->students.begin();
    while(it != this->students.end())
    {
        it2= it;
        it2++;
        while(it2 != this->students.end())
        {
            if (sortFeild == Field::Code)
            {
                if (sortMode == SortMode::Asc)
                {
                    if (it->code > it2->code)
                    {
                        stu = *it;
                        *it = *it2;
                        *it2 = stu;
                    }
                }
                else
                {
                    if (it->code > it2->code)
                    {
                        stu =*it;
                        *it = *it2;
                        *it2 = stu;
                    }
                }
                
            }
        }
    }
    return this;
}

Student* Student::clearError()
{
    error = false;
    this->errorMessage.clear();
    return this;
}

Student* Student::setError(string errorMessage)
{
    error = true;
    this->errorMessage = errorMessage;
    return this;
}

Student* Student::limit(size_t count)
{
    this->limitCount = count;
    return this;
}

Student* Student::first(bool filteredData = false)
{
    if (filteredData)
    {
        for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
        {
            if(it->filtered)
            {
                this->studentModel = *it;
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

Student* Student::last(bool filteredData = false)
{
    return this;
}

void Student::debug()
{
    cout << endl;
    cout << "************************" << endl;
    cout << "code: " << this->studentModel.code << endl;
    cout << "name: " << this->studentModel.name << endl;
    cout << "avrage: " << this->studentModel.average << endl;
    cout << "************************" << endl;
}