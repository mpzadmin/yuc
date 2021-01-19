#include<iostream>
#include<string>
#include<list>

using namespace std;

enum  Field {Code, Name, Average};
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
    list<StudentModel> lst;
    list<StudentModel>::iterator itr;
      bool error;
      string errorMassage;
    protected:
    public:
      Student();
      ~ Student();
      Student* setError(string errorMassage);
      Student* clearError();
      Student* setCode(int code);
      Student*  setName(string name);
      Student* setAverage(float average);
      Student* list();
      Student*  add(); 
      Student* remove();
      
      void debug();
      int getCode();
      string getName();
      string getError();
      float  getAverage();
      bool fail();
      bool find(Field searchField);
     
      
      
};

Student::Student()
{
    this->lst.clear();
    this->error=false;
}

Student::~Student()
{

}

void Student::debug()
{
    cout<<endl;
    cout<<"****************"<<endl;
    cout<<"code : "<<this->getCode()<<endl;//or this->StudentModel.code
    cout<<"Name : "<<this->getName()<<endl;//or this->StudentModel.name
    cout<<"Average : "<<this->getAverage()<<endl;//or this->StudentModel.average
    cout<<"****************"<<endl;

}
bool Student::fail()
{
    return this->error;
}
string Student::getError()
{
   
    return this->error? this->errorMassage: "";
}

Student * Student::setCode(int code)
{
    this->studentModel.code=code;
    return this;
}

Student *Student::setName(string name)
{
    this->studentModel.name=name;
    return this;
}

Student* Student::setAverage(float average)
{
    this->studentModel.average=average;
    return this;
}

string  Student::getName()
{
    return this->studentModel.name;
}

int Student::getCode()
{
    return this->studentModel.code;
}

float Student::getAverage()
{
    return this->studentModel.average;
}
Student* Student::list()
{
    if(this->lst.size()<=0)
    {
        return this;
    }
    else
    {
        //want you 1 or 2
        /*
        1.
        for(StudentModel stu : lst)
        {
            cout<<"Code : "<<stu.code<<"   " 
            <<"Name : "<<stu.name<<"   "<<"Average : "<<stu.average<<endl;
        }
        */
        //2.
        for(itr=lst.begin(); itr!=lst.end(); itr++)
        {
            cout<<itr->name<<"    "<<itr->average<<"   "<<itr->code<<endl;
        }
        return this;
    }
    
}
Student *Student::add()
{
    this->clearError();
    if(this->find(Field::Code)==false)
    {
          lst.push_back(this->studentModel); 
    }
    else
    {
        string bug="This Data exsist in list";
        setError(bug);
    }
    
   
    return this; 
}
Student* Student::remove()//*************
{
    bool result=false;
    clearError();
    itr=lst.begin();
    for(itr; itr!=lst.end(); itr++)
    {
        if(itr->code==studentModel.code)
        {
            this->lst.erase(itr);
            result=true;
            break;

        }
    }
    if(!result)
    {
        this->setError("This Data exsist in list");
    }
    return this;
}
bool Student:: find(Field searchField)
{
    bool result=false;
    if(this->lst.size()<=0) return result;

    for(itr=lst.begin(); itr!=lst.end(); itr++)
    {
        if(searchField==Field::Code)
        {
            if(itr->code==this->studentModel.code)
            {
              /*or
                this->setName(itr->name);
                this->setAverage(itr->average);
                */
               studentModel=*itr;
                result=true;
                break;
            }
        }
        else if(searchField==Field::Name)
        {
            if(itr->name==this->studentModel.name)
            {
                /*or
                this->setCode(itr->code);
                this->setAverage(itr->average);
                */
               studentModel=*itr;
                result= true;
                break;
            }
        }
        else 
        {

            
            if(itr->average==this->studentModel.average)
            {
                /*or
                this->setCode(itr->code);
                this->setName(itr->name);
                */
                studentModel=*itr;
                result=true;
                break;
            }  
        } 
    }
    return result;
    
}
Student* Student::clearError()
{
    this->error=false;
    this->errorMassage.clear();
    return this;
}
Student* Student::setError(string bug)
{
    this->error=true;
    this->errorMassage =bug;
    return this;
}