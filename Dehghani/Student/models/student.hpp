#include <iostream>
#include <string>
#include <fstream>
#include <list>

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
        list <StudentModel> students;

        bool error;
    protected:

    public:
        Student();
        ~Student();
};