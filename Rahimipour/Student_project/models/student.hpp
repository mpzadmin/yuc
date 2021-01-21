#include <iostream>
#include <string>
#include <list>
#include <fstream>

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
        StudentModel()// instructor
        {
            filtered = false;
        }
};

typedef list<StudentModel>::iterator StudentIterator;// SMIterator : student
typedef list<StudentModel>::reverse_iterator RStudentIterator;// Az akhar shor mikone be  aval

class Student // main class(student class)
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
        void debug(); // to show data 

        Student* setCode(int code);
        int getCode();

        Student* setName(string name);
        string getName();

        Student* setAverage(float average);
        float getAverage();

        //Student* list();// print all data in list sutdent.
        Student* list2(bool showFilteredData = false);
        Student* add();// 
        Student* remove();

        bool find(Field searchField); // we want to return true or false.
        Student* filter(Field filterField);
        Student* sort(Field sortField, SortMode SortMode = SortMode::Asc);
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
    this->limitCount = 0;

}

Student::~Student()
{
    
}

void Student::debug()
{
    cout << endl;
    //cout << "*************" << endl;
    cout << "Code: " << this->getCode() << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Average: " << this->getAverage() << endl;
    cout << "*************" << endl;
}

bool Student::fail()
{
    return this->error;
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

Student* Student::setAverage(float average)
{
    this->studentModel.average = average;
    return this;
}

float Student::getAverage()
{
    return this->studentModel.average;
}
/* the buttom code down this one is more profetional.
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
        cout << "Average: " << stu.average << endl;
        cout << "-_-_-_-_-_-_-_-_-_-_-" << endl;
    }

    return this;
}
*/

Student* Student::list2(bool showFilteredData)
{
    size_t counter = 0;
    if (this->students.size() <= 0)
    {
        return this;
    }

    for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
    {
        if (showFilteredData && (!it->filtered)) continue; // mipare aval halghe
        cout << "Code: " << it->code << endl;
        cout << "Name: " << it->name << endl;
        cout << "Average: " << it->average << endl;
        cout << "*-*-*-*-*-**-*-*-*-*-*" << endl;
        counter++;
        if ((this->limitCount > 0) && (counter >= this->limitCount))
        {
            break;
        }
    }

    return this;
}

Student* Student::add()
{
    this->clearError();
    if ( !this->find(Field::Code) )
    {
        this->students.push_back(this->studentModel);
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
        if (it->code == this->studentModel.code)
        {
            this->students.erase(it);
            result = true;
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
    if (this->students.size() <= 0)
    {
        return result;
    }
    for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
    {
        if (searchField == Field::Code)
        {
            if (it->code == this->studentModel.code)
            {
                /** we can use this. or down of it which is not comment.
                this->setCode(it->code);
                this->setName(it->name);
                this->setAverage(it->average);
                */
                this->studentModel = *it;
                result = true;
                break;
            }
        }

        else if (searchField == Field::Name)
        {
            if (it->name == this->studentModel.name)
            {
                this->studentModel = *it;
                result = true;
                break;
            }
            
        }

        else // will be average
        {
            if (it->average == this->studentModel.average)
            {
                this->studentModel = *it;
                result = true;
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
            if (it->code == this->studentModel.code)
            {
                it->filtered = true;
            }
        }
        else if (filterField == Field::Name)
        {
            if (it->name == this->studentModel.name)
            {
                it->filtered = true;
            } 
        }

        else if (filterField == Field::Average)
        {
            if (it->average == this->studentModel.average)
            {
                it->filtered = true;
            }
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
        // or advance(it2, 1)
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
                else // Means Desc
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
                else // Means Desc
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

Student* Student::limit(size_t count)
{
    this->limitCount = count;
    return this;
}

Student* Student::first(bool filteredData)
{
    if (filteredData)
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
Student* Student::last(bool filteredData)
{
        if (filteredData)
    {
        for (RStudentIterator it = this->students.rbegin(); it != this->students.rend(); it++)
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
        this->studentModel = this->students.back();
    }
    
    return this;
    return this;
}
