#include <iostream>
#include <string>
#include <list>

using namespace std;

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

        Student* setCode(int code);
        Student* setName(string name);
        Student* setAverage(float average);

        int getCode();
        string getName();
        float getAverage();

        Student* list(bool showFilterData = false);
        Student* add();
        Student* remove();
        
        bool find(Field searchField);
        Student* filter(Field filterField);
        Student* sort(Field sortField, SortMode sortMode = SortMode::Asc);
        Student* limit(size_t count);

        void debug();

        bool fail();
        Student* clearError();
        Student* setError(string errorMessage);
        string getError();
        Student* first(bool FilteredData = false);
        Student* last(bool FilteredData = false);
};

Student::Student()
{
    this->error = false;
    this->limitCount = 0;
}   

Student::~Student()
{
    
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

Student* Student::list(bool showFilterData)
{
    size_t counter = 0;

    if (this->students.size() <= 0)
        return this;

    for (StudentIterator it = students.begin(); it != students.end(); it++)
    {
        if (showFilterData && (!it->filtered))
            continue;

        cout << "Code   : " << it->code << endl;
        cout << "Name   : " << it->name << endl;
        cout << "Average: " << it->average << endl;
        cout << "----------------------------" << endl;
        counter++;

        if ((this->limitCount > 0) && (counter >= this->limitCount))
            break;
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
        this->setError("The data exists!");
    }
    return this;
}

Student* Student::remove()
{
    this->clearError();
    bool result = false;
    for (StudentIterator it = students.begin(); it != students.end(); it++)
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
        this->setError("Not Found!");
    }
    return this;
}

bool Student::find(Field searchField)
{
    bool result = false;
    for (StudentIterator it = students.begin(); it != students.end(); it++)
    {
        if (searchField == Field::Code)
        {
            if (it->code == studentModel.code)
            {
                this->studentModel = *it;
                result = true;
                break;
            }
        }
        else if (searchField == Field::Name)
        {
            if (it->name == studentModel.name)
            {
                this->studentModel = *it;
                result = true;
                break;
            }
        }
        else
        {
            if (it->average == studentModel.average)
            {
                this->studentModel = *it;
                result = true;
                break;
            }
        }
    }
    return result;
}

Student* Student::filter(Field searchField)
{
    this->clearError();
    for (StudentIterator it = students.begin(); it != students.end(); it++)
    {
        it->filtered = false;
        if (searchField == Field::Code)
        {
            if (it->code == studentModel.code)
                it->filtered = true;
        }
        else if (searchField == Field::Name)
        {
            if (it->name == studentModel.name)
                it->filtered = true;
        }
        else if (searchField == Field::Average)
        {
            if (it->average == studentModel.average)
                it->filtered = true;
        }
    }
    return this;
}

Student* Student::sort(Field sortField, SortMode sortMode)
{
    StudentIterator it, it2;
    StudentModel stu;

    it = this->students.begin();
    while (it != this->students.end())
    {
        it2 = it;
        it2++;
        while (it2 != this->students.end())
        {
            if (sortField == Field::Code)
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
                    if (it->code < it2->code)
                    {
                        stu = *it;
                        *it = *it2;
                        *it2 = stu;
                    }
                }
            }
            else if (sortField == Field::Name)
            {
                if (sortMode == SortMode::Asc)
                {
                    if (it->name > it2->name)
                    {
                        stu = *it;
                        *it = *it2;
                        *it2 = stu;
                    } 
                }
                else
                {
                    if (it->name < it2->name)
                    {
                        stu = *it;
                        *it = *it2;
                        *it2 = stu;
                    }
                }
            }
            else if (sortField == Field::Average)
            {
                if (sortMode == SortMode::Asc)
                {
                    if (it->average > it2->average)
                    {
                        stu = *it;
                        *it = *it2;
                        *it2 = stu;
                    }
                }
                else
                {
                    if (it->average < it2->average)
                    {
                        stu = *it;
                        *it = *it2;
                        *it2 = stu;
                    }
                }
            }
            it2++;
        }
        it++;
    }
    
    return this;
}

Student* Student::limit(size_t count)
{
    this->limitCount = count;
    return this;
}

void Student::debug()
{
    cout << endl;
    cout << "***********************************" << endl;
    cout << "Code: " << this->getCode() << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Average: " << this->getAverage() << endl;
    cout << "***********************************" << endl;
}

bool Student::fail()
{
    return this->error;
}

Student* Student::clearError()
{
    this->error = false;
    this->errorMessage.clear();
    return this;
}

Student* Student::setError(string errorMessage)
{
    this->error = true;
    this->errorMessage = errorMessage;
    return this;
}

string Student::getError()
{
    return this->error ? this->errorMessage : "";
}
Student* Student::first(bool FilteredData = false)
{
   if (FilteredData)
   {
       for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
       {
           if (it->filtered)
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