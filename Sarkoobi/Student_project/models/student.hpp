#include <iostream>
#include <string>
#include <list>


using namespace std;
enum Field {Code, Name, Average};
enum SortMode {Asc, Desc}
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
        StudentModel studentmodel;
        list<StudentModel> students;
    
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
        Student* setAverage(float average);
        float getAverage();
        Student* list(bool showFilteredData = false);
        //Student* list2();
        
        Student* add();
        Student* remove();
        bool find(Field searchField);
        Student* filter(Field filterField);
        Student* sort(Field sortField, SortMode sortMode = SortMode::Asc);

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
void Student::debug()
{
    cout << endl;
    cout << "*******************************************" << endl;
    cout << "Code: " << this->getCode() << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Average: " << this->getAverage() << endl;
    cout << "*******************************************" << endl;
}

bool Student::fail()
{
    return this->error;
}

string Student::getError()
{
    return this->error ? this->errorMessage : " ";
}

Student* Student::setCode(int code)
{
    this->studentmodel.code = code;
    return this;
}

int Student::getCode()
{
    return this->studentmodel.code;
}
Student* Student::setName(string name)
{
    this->studentmodel.name = name;
    return this;
}

float Student::getAverage()
{
    return this->studentmodel.average;
}
/*
Student* Student::list()
{
    if(this->students.size() <= 0)
    {
        return this;
    }

    for (studentmodel stu : this->students)
    {
        cout << "code: " << stu.code << endl;
        cout << "Name: " << stu.name << endl;
        cout << "Average: " << stu.average << endl;
        cout << endl;
    }
    return this;
} 
*/
Student* Student::list(bool showFilteredData)
{
    if(this->students.size() <= 0)
    {
        return this;
    }

    for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
    {
        if (showFilteredData && (!it->filtered))
            continue;
        
        cout << "code: " <<it->code << endl;
        cout << "Name: " <<it->name << endl;
        cout << "Average: " <<it->average << endl;
        cout << endl;
    }
    return this;
} 

Student* Student::add()
{
    if ( !this->find(Field::Code) )
        this->students.push_back(this->studentmodel); 
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
        if (it->code == this->studentmodel.code)
        {
            this->students.erase(it);
            break;
        }
    }
    if (!result)
    {
        this->setError("The record not found!");
    }
    
    return this;
}

bool Student::find(Field searchField)
{
    bool result = false;
    if(this->students.size() <= 0)
        return result;
    
    for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
    {
        if (searchField == Field::Code)
        {
            if (it->code == this->studentmodel.code)
            {
                this->studentmodel = *it; 
                result true;
                break;
            }
            
        }
        else if (searchField == Field::Name)
        {
            if (it->name == this->studentmodel.name)
            {
                this->studentmodel = *it;
                result true;
                break;
            }
        }
        else
        {
            if (it->average == this->studentmodel.average)
            {
                this->studentmodel = *it;
                result true;
                break;
            }
        }
    }
    return result;
}
Student* Student::filter(Field filterField)
{
    this->clearError();
    for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
    {
        it->filtered = false;
        if (filterField == Field::Code)
        {
            if (it->code == this->studentmodel.code)
                it->filtered = true;
        }
        else if (filterField == Field::Name)
        {
            if (it->code == this->studentmodel.name)
                it->filtered = true;
        }
        else if (filterField == Field::Average)
        {
            if (it->code == this->studentmodel.average)
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
