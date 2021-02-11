#include<iostream>
#include<fstream>
#include<string>
#include<list>

using namespace std;

enum Field {Code, Name,Average};
enum SortMode {Asc, Desc};


Field fieldName;



class StudentModel
{
     public:
         int code;
         string name;
         float avarage;
         bool filtered;
         StudentModel()
         {
             filtered = false;
         }

};

typedef list<StudentModel>::iterator StudentIterator;
typedef list<StudentModel>::reverse_iterator RStudentIterator;

class Student
{
     private:
         StudentModel studentModel;
         list <StudentModel> students;

         size_t limitCount;

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

         Student* list(bool showFilteredData = false);
        // Student* list();
         Student* add();
         Student* remove();
         Student* filter(Field filteredField);
         Student* sort(Field sortField, SortMode sortMode = SortMode :: Asc); 
         Student* limit(size_t count);
         Student* first(bool filteredData = false);
         Student* last(bool filteredData = false);



         bool find(Field searchField);
         bool fail();

         string getError();
         Student* clearError();
         Student* setError(string errorMessage);



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

Student* Student::list(bool showFilteredData)
{
    size_t counter = 0;
    if (this->students.size() <= 0)
    {
        return this;
    }

    
    for ( StudentIterator it = this->students.begin(); it != this->students.end(); it++)
    {
        if(showFilteredData && (!it->filtered)) continue;

        cout << "Code: " << it->code << endl;
        cout << "Name: " << it->name << endl;
        cout << "Average: " << it->avarage << endl;
        cout << endl;  
        counter++;
        if ((this->limitCount > 0) && (counter >= this->limitCount)) break;    
    }

    return this;
}
/*
Student* Student::list()
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
     this->clearError();
    if (!this->find(Field::Code) )
     {
        this->students.push_back(this->studentModel);
     }
    else
    {
        this->setError("The record exists!");
    }        
    return this;
}

bool Student::find(Field searchField)
{
    bool result = false;
    if( this -> students.size()<= 0 ) return result;
     {
    for(StudentIterator it = this -> students.begin(); it != this -> students.end(); it++ )
    {
     if(searchField == Field :: Code)
      {
        if(it->code == this->studentModel.code)
        {
            this->studentModel = *it;
            result = true;
            break;

        }
      }

        else if(searchField == Field :: Name)
        {
             if(it->name == this->studentModel.name)
         {
            this->studentModel = *it;
            result = true;
            break;

         }

        }
        else
        {
         if(it->avarage == this->studentModel.avarage)
          {
             this->studentModel = *it;
             result = true;
             break;

          }
        }
    } 
 }
 return this;

}

Student* Student :: filter(Field filteredField)
{
    this->clearError();
    for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
    {
        it->filtered = false;
        if (filteredField == Field::Code)
        {
            if (it->code == this->studentModel.code)
                it->filtered = true;    
        }
        else if (filteredField == Field::Name)
        {
            if (it->name == this->studentModel.name)
                it->filtered = true;    
        }
        else if (filteredField == Field::Average)
        {
            if (it->avarage == this->studentModel.avarage)
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
                    if (it->avarage > it2->avarage)
                    {
                        stu = *it;
                        *it = *it2;
                        *it2 = stu;    
                    } 
                }
                else
                {
                    if (it->avarage < it2->avarage)
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
    return this;
}
Student* Student::limit(size_t count)
{
    this->limitCount = count;
    return this;
}
Student* Student::first(bool filteredData)
{
    if(filteredData)
    {
        for (StudentIterator it = this->students.begin(); it != this->students.end(); it++)
        {
            if(it -> filtered)
            {
                this->studentModel = *it;
                break;
            }
        }
    }
    else
    {
        this->studentModel = this->students.front() ;
    }
    return this;
      
}

Student* Student::last(bool filteredData = false)
{
    if(filteredData)
    {
        for(RStudentIterator it = this->students.rbegin(); it !=this->students.rend();it++)

         if(it -> filtered)
            {
                this->studentModel = *it;
                break;
            }
            else
            {
               this->studentModel = this->students.back() ; 
            }
            
    }
    return this;
}




























 //https://en.cppreference.com/w/cpp/links/libs